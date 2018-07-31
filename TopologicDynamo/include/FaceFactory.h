#pragma once

#include <TopologyFactory.h>

namespace Topologic
{
	ref class FaceFactory : TopologyFactory
	{
	public protected:
		virtual Topology^ Create(const TopologicCore::Topology::Ptr& kpTopology) override;
	};

}