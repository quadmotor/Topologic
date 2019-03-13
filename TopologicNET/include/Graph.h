#pragma once

#include <TopologicCore/include/Graph.h>

#ifdef TOPOLOGIC_DYNAMO
using namespace Autodesk::DesignScript::Runtime;
#endif

using namespace System::Collections::Generic;

namespace Topologic {
	ref class Vertex;
	ref class Edge;
	ref class Topology;

	public ref class Graph
	{
	public:
		static Graph^ ByVerticesEdges(List<Vertex^>^ vertices, List<Edge^>^ edges);


#ifdef TOPOLOGIC_DYNAMO
		static Graph^ ByTopology(
			Topology^ topology,
			[DefaultArgument("true")] bool direct,
			[DefaultArgument("false")] bool viaSharedTopologies,
			[DefaultArgument("false")] bool viaSharedApertures,
			[DefaultArgument("false")] bool toExteriorTopologies,
			[DefaultArgument("false")] bool toExteriorApertures);
#else
		static Graph^ ByTopology(
			Topology^ topology,
			bool direct,
			bool viaSharedTopologies,
			bool viaSharedApertures,
			bool toExteriorTopologies,
			bool toExteriorApertures);
#endif

		property List<Vertex^>^ Vertices
		{
			List<Vertex^>^ get();
		}

		property List<Edge^>^ Edges
		{
			List<Edge^>^ get();
		}

		property Topology^ Topology
		{
			Topologic::Topology^ get();
		}

		Graph^ AddVertex(Vertex^ vertex);

		Graph^ AddEdge(Edge^ edge);

		int VertexDegree(Vertex^ vertex);

		List<Vertex^>^ AdjacentVertices(Vertex^ vertex);

		Graph^ Connect(Vertex^ vertex1, Vertex^ vertex2);

		bool ContainsVertex(Vertex^ vertex);

		bool ContainsEdge(Edge^ edge);

		property List<int>^ DegreeSequence
		{
			List<int>^ get();
		}

		property double Density
		{
			double get();
		}

		//property bool IsC

	public protected:
		Graph(const std::shared_ptr<TopologicCore::Graph>& kpCoreGraph);

	protected:
		virtual ~Graph();

		std::shared_ptr<TopologicCore::Graph>* m_pCoreGraph;
	};
}