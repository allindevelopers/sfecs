#ifndef ENTITY_H
#define ENTITY_H

#include <bitset>
#include <string>
#include <cstddef>
#include <typeinfo>
#include "SFECS/BitSize.hpp"
#include "SFECS/ImmutableBag.hpp"
#include "SFECS/EntityManager.hpp"
#include "SFECS/ComponentTypeManager.hpp"

namespace sfecs {

	class Component;
	class ComponentType;
	class Manager;
	//class EntityManager;
	
	class Entity {

		private:
			int id;
			long int uniqueId;
			std::bitset<BITSIZE> typeBits;
			std::bitset<BITSIZE> systemBits;
			Manager * world;
			EntityManager * entityManager;
			
			Entity(const Entity&) = delete;
			Entity& operator=(const Entity&) = delete;
			
		protected:

		public:
			Entity(Manager * world, int id);
			~Entity();
			int getId();
			void setUniqueId(long int uniqueId);
			long int getUniqueId();

			std::bitset<BITSIZE> getTypeBits();
			void addTypeBit(std::bitset<BITSIZE> bit);
			void removeTypeBit(std::bitset<BITSIZE> bit);
			std::bitset<BITSIZE> getSystemBits();
			void addSystemBit(std::bitset<BITSIZE> bit);
			void removeSystemBit(std::bitset<BITSIZE> bit);
			void setSystemBits(std::bitset<BITSIZE> systemBits);
			void setTypeBits(std::bitset<BITSIZE> typeBits);
			void reset();

			std::string toString();

			Entity& addComponent(Component * c);

			//Might change to non template
			template<typename c>
			Entity& removeComponent() {
				entityManager->removeComponent(*this,ComponentTypeManager::getTypeFor<c>());
				return *this;
			}

			Entity& removeComponent(ComponentType & type);


			Component * getComponent(ComponentType & type);

			template<typename c>
			c * getComponent() {
				return (c*)entityManager->getComponent(*this,ComponentTypeManager::getTypeFor<c>());
			}

			ImmutableBag<Component*> & getComponents();

			bool isActive();
			void refresh();
			void remove();
			void setGroup(std::string group);
			void setTag(std::string tag);


	};
}
#endif // $(Guard token)
