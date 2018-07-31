#pragma once

#include <Topology.h>

#include <TopologicCore/include/Topology.h>

using namespace System::Collections::Generic;

namespace Topologic
{
	ref class TopologyFactory abstract
	{
	public protected:
		virtual Topology^ Create(const TopologicCore::Topology::Ptr& kpTopology) abstract;
	};
}