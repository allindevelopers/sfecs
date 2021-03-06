#ifndef ENT_PROCESS_SYS_H
#define ENT_PROCESS_SYS_H

#include "SFECS/ImmutableBag.hpp"
#include "SFECS/EntitySystem.hpp"

namespace sfecs {

	class Entity;

	class EntityProcessingSystem : public EntitySystem {

		protected:
			EntityProcessingSystem() {};
			virtual void processEntity(Entity &e) = 0;
			void processEntities(ImmutableBag<Entity*> & bag);
			virtual bool checkProcessing();
	};
}

#endif // $(Guard token)
