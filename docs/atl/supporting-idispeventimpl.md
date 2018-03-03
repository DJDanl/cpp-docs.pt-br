---
title: Suporte IDispEventImpl | Microsoft Docs
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- cpp-windows
ms.tgt_pltfrm: 
ms.topic: article
f1_keywords:
- IDispEventImpl
dev_langs:
- C++
helpviewer_keywords:
- event sink maps, declaring
- IDispEventImpl class, advising and unadvising
- SINK_ENTRY macro
- type libraries, importing
- ATL, IDispEventImpl support in COM objects
- BEGIN_SINK_MAP macro
- IDispEventImpl class, declaring
ms.assetid: b957f930-6a5b-4598-8e4d-8027759957e7
caps.latest.revision: 
author: mikeblome
ms.author: mblome
manager: ghogen
ms.workload:
- cplusplus
ms.openlocfilehash: 8bf10a68ae15743a637df2dee52bee83c3dfcbe0
ms.sourcegitcommit: 8fa8fdf0fbb4f57950f1e8f4f9b81b4d39ec7d7a
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 12/21/2017
---
# <a name="supporting-idispeventimpl"></a>Suporte IDispEventImpl
A classe de modelo [IDispEventImpl](../atl/reference/idispeventimpl-class.md) pode ser usado para fornecer suporte para Coletores de ponto de conexão em sua classe ATL. Um coletor de ponto de conexão permite que a sua classe manipular eventos disparados por objetos externos. Esses coletores de ponto de conexão são mapeadas com um mapa de coletor de eventos, fornecido por sua classe.  
  
 Para implementar corretamente um coletor de ponto de conexão para a sua classe, as etapas a seguir devem ser concluídas:  
  
-   Importar as bibliotecas de tipo para cada objeto externo  
  
-   Declare o `IDispEventImpl` interfaces  
  
-   Declarar um mapa de coletor de eventos  
  
-   Avisar e unadvise os pontos de conexão  
  
 As etapas envolvidas na implementação de um coletor de ponto de conexão são realizadas pela modificação dos apenas o arquivo de cabeçalho (. h) de sua classe.  
  
## <a name="importing-the-type-libraries"></a>Importando as bibliotecas de tipo  
 Para cada objeto cujos eventos você deseja manipular externo, você deve importar a biblioteca de tipos. Esta etapa define os eventos que podem ser manipulados e fornece informações que são usadas ao declarar o mapa de coletor de evento. O [#import](../preprocessor/hash-import-directive-cpp.md) diretiva pode ser usada para fazer isso. Adicionar necessários `#import` diretivas linhas para cada interface de Despache você dará suporte para o arquivo de cabeçalho (. h) de sua classe.  
  
 O exemplo a seguir importa a biblioteca de tipos de um servidor COM externo (`MSCAL.Calendar.7`):  
  
 [!code-cpp[NVC_ATL_Windowing#141](../atl/codesnippet/cpp/supporting-idispeventimpl_1.h)]  
  
> [!NOTE]
>  Você deve ter um separado `#import` instrução para cada biblioteca de tipo externo oferecerá suporte.  
  
## <a name="declaring-the-idispeventimpl-interfaces"></a>Declarando as Interfaces IDispEventImpl  
 Agora que você importou as bibliotecas de tipo de cada interface de distribuição, você precisa declarar separada `IDispEventImpl` interfaces para cada interface de Despache externo. Modificar a declaração da classe adicionando um `IDispEventImpl` interface de declaração para cada objeto externo. Para obter mais informações sobre os parâmetros, consulte [IDispEventImpl](../atl/reference/idispeventimpl-class.md).  
  
 O código a seguir declara duas Coletores de ponto de conexão, para o `DCalendarEvents` interface para o objeto COM implementado pela classe `CMyCompositCtrl2`:  
  
 [!code-cpp[NVC_ATL_Windowing#142](../atl/codesnippet/cpp/supporting-idispeventimpl_2.h)]  
  
## <a name="declaring-an-event-sink-map"></a>Declarando um mapa de coletor de eventos  
 Em ordem para as notificações de eventos a ser manipulada pela função apropriada, sua classe deve rotear cada evento para seu manipulador correto. Isso é conseguido declarando um mapa de coletor de eventos.  
  
 ATL fornece várias macros, [BEGIN_SINK_MAP](reference/composite-control-macros.md#begin_sink_map), [END_SINK_MAP](reference/composite-control-macros.md#end_sink_map), e [SINK_ENTRY_EX](reference/composite-control-macros.md#sink_entry_ex), que facilitam esse mapeamento. O formato padrão é o seguinte:  
  
 `BEGIN_SINK_MAP(comClass)`  
  
 `SINK_ENTRY_EX(id, iid, dispid, func)`  
  
 `. . . //additional external event entries`  
  
 `END_SINK_MAP()`  
  
 O exemplo a seguir declara um mapa de coletor de eventos com dois manipuladores de eventos:  
  
 [!code-cpp[NVC_ATL_Windowing#136](../atl/codesnippet/cpp/supporting-idispeventimpl_3.h)]  
  
 A implementação está quase concluída. A última etapa relacionado à assessoria e unadvising das interfaces externas.  
  
## <a name="advising-and-unadvising-the-idispeventimpl-interfaces"></a>Orientando e Unadvising as Interfaces IDispEventImpl  
 A etapa final é implementar um método que será de aviso (ou unadvise) todos os pontos de conexão de tempo adequado. Este informando deve ser feita antes que a comunicação entre os clientes externos e seu objeto podem ocorrer. Antes do objeto se torna visível, cada interface de Despache externo com suporte do seu objeto será consultado para interfaces de saída. Uma conexão é estabelecida e uma referência para a interface de saída é usada para manipular eventos do objeto. Esse procedimento é chamado de "informando".  
  
 Após o objeto com as interfaces externas, as interfaces de saída devem ser notificadas de que eles não são mais usados pela sua classe. Esse processo é conhecido como "unadvising".  
  
 Devido à natureza exclusiva de objetos COM, esse procedimento varia, em execução entre implementações e de detalhes. Esses detalhes estão além do escopo deste tópico e não são resolvidos.  
  
## <a name="see-also"></a>Consulte também  
 [Princípios básicos de objetos COM da ATL](../atl/fundamentals-of-atl-com-objects.md)

