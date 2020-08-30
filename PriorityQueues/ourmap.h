#include <string>
using namespace std;

template <typename V>
class MapNode
{
public:
	string key;
	V value;
	MapNode* next;
	MapNode(string key, V value)
	{
		this->key = key;
		this->value = value;
		next = NULL;
	}
	~MapNode()
	{
		delete next;
	}
	
};

template <typename V>
class ourmap
{
	MapNode<V>** buckets;
	int count;
	int numBuckets;
public:
	ourmap()
	{
		count = 0;
		numBuckets = 5;
		buckets = new MapNode<V>*[numBuckets];

		for (int i = 0; i < numBuckets; i++)
		{
			buckets[i] = NULL;
		}
	}
	~ourmap()
	{
		for (int i = 0; i < numBuckets; i++)
		{
			delete buckets[i];
		}

		delete [] buckets;
	}

	int size()
	{
		return count;
	}

	V getValue(string key)
	{
		int bucketIndex  = getBucketIndex(key);
		MapNode<V>* head = buckets[bucketIndex];
		while(head != NULL)
		{
			if (head->key == key) // if the key already exists
			{
				return head->value;
			}

			head = head->next;
		}

		return 0;

	}

private:

	int getBucketIndex(string key)
	{
		int hashCode = 0;
		int currentCoeff = 1;

		for (int i = key.length() - 1; i >= 0; i--)
		{
			hashCode += key[i] * currentCoeff;
			hashCode = hashCode % numBuckets;
			currentCoeff *= 37;

			// to ensure currentCoeff does not go out of range
			currentCoeff = currentCoeff % numBuckets;
		}

		return hashCode % numBuckets; 
	}

	void rehash()
	{
		MapNode<V>** temp = buckets;
		buckets = new MapNode<V>*[2*numBuckets];

		for (int i = 0; i < 2*numBuckets; i++)
		{
			buckets[i] = NULL;
		}

		int oldBucketCount = numBuckets;
		numBuckets *= 2;
		count = 0;
	}

public:

	void insert(string key, V value)
	{
		int bucketIndex = getBucketIndex(key);
		MapNode<V>* head = buckets[bucketIndex];

		while(head != NULL)
		{
			if (head->key == key) // if the key already exists
			{
				head->value = value;
				return;
			}

			head = head->next;
		}

		head = buckets[bucketIndex]; // reset the head
		MapNode<V>* node = new MapNode<V>(key, value);
		node->next = head;
		buckets[bucketIndex] = node;
		count++;

		double loadFactor = (double)(1.0*count)/numBuckets; 
		if (loadFactor > 0.7)
		{
			rehash();
		}
	}

	V remove(string key)
	{
		int bucketIndex = getBucketIndex(key);
		MapNode<V>* head = buckets[bucketIndex];
		MapNode<V>* prev = NULL;

		while(head != NULL)
		{
			if (head->key == key) 
			{
				if (prev == NULL)
				{
					buckets[bucketIndex] = head->next;
				}

				else
				{
					prev->next = head->next;
				}
				
				V value = head->value;
				head->next = NULL;
				delete head;
				count--;
				return value;
			}

			prev = head;
			head = head->next;
		}

		return 0;
	}
};