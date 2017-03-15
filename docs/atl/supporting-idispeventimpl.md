---
title: "Suporte IDispEventImpl | Microsoft Docs"
ms.custom: ""
ms.date: "12/03/2016"
ms.prod: "visual-studio-dev14"
ms.reviewer: ""
ms.suite: ""
ms.technology: 
  - "devlang-cpp"
ms.tgt_pltfrm: ""
ms.topic: "article"
f1_keywords: 
  - "IDispEventImpl"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "ATL, Suporte de IDispEventImpl em objetos COM"
  - "Macro de BEGIN_SINK_MAP"
  - "mapas do coletor de eventos, declarando"
  - "Classe de IDispEventImpl, unadvising e conselhos"
  - "Classe de IDispEventImpl, declarando"
  - "Macro de SINK_ENTRY"
  - "bibliotecas de tipo, importando"
ms.assetid: b957f930-6a5b-4598-8e4d-8027759957e7
caps.latest.revision: 11
caps.handback.revision: 6
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# Suporte IDispEventImpl
[!INCLUDE[vs2017banner](../assembler/inline/includes/vs2017banner.md)]

A classe [IDispEventImpl](../atl/reference/idispeventimpl-class.md) de modelo pode ser usada para fornecer suporte para dissipadores de ponto de conexão em sua classe de ATL.  Coleta de um ponto de conexão permite que a classe trata os eventos acionados de COM objetos externos.  Esses dissipadores de ponto de conexão são mapeados com um mapa do coletor de eventos, já que por sua classe.  
  
 Para implementar corretamente coletor de um ponto de conexão para sua classe, as seguintes etapas devem ser concluídas:  
  
-   Importar as bibliotecas de tipo para cada objeto externo  
  
-   Declare as interfaces de `IDispEventImpl`  
  
-   Declare um mapa do coletor de eventos  
  
-   Seja recomendável e unadvise os pontos de conexão  
  
 As etapas envolvidas em qualquer implementar um ponto de conexão do coletor são executadas somente alterando o arquivo de cabeçalho \(.h\) de sua classe.  
  
## Importando as bibliotecas de tipo  
 Para cada objeto externo cujos eventos que você deseja tratar, você deve importar a biblioteca de tipos.  Esta etapa define os eventos que podem ser tratados e fornece informações que é usada para declarar o mapa do coletor de eventos.  A política de [\#import](../Topic/%23import%20Directive%20\(C++\).md) pode ser usada para fazer isso.  Adicione as linhas necessárias políticas de `#import` para cada interface de distribuição que você oferece suporte ao arquivo de cabeçalho \(.h\) de sua classe.  
  
 O exemplo a seguir importa a biblioteca de tipos de um servidor externo COM \(`MSCAL.Calendar.7`\):  
  
 [!code-cpp[NVC_ATL_Windowing#141](../atl/codesnippet/CPP/supporting-idispeventimpl_1.h)]  
  
> [!NOTE]
>  Você deve ter uma declaração separada de `#import` para cada biblioteca externa do tipo que você ele.  
  
## Declarando interfaces de IDispEventImpl  
 Agora que você importou as bibliotecas de tipo de cada distribuição interface, você precisará declarar interfaces de `IDispEventImpl` separadas para cada interface externo de distribuição.  Altere a declaração de classe adicionando uma declaração de interface de `IDispEventImpl` para cada objeto externo.  Para obter mais informações sobre parâmetros, consulte [IDispEventImpl](../atl/reference/idispeventimpl-class.md).  
  
 O código a seguir declara dois dissipadores de ponto de conexão, para a interface de `DCalendarEvents` , porque o objeto COM implementado pela classe `CMyCompositCtrl2`:  
  
 [!code-cpp[NVC_ATL_Windowing#142](../atl/codesnippet/CPP/supporting-idispeventimpl_2.h)]  
  
## Declarando um mapa do coletor de eventos  
 Para que as notificações de eventos são tratadas pela função apropriada, sua classe devem redirecionar\-se cada evento ao seu identificador correto.  Isso é conseguido declarando um mapa do coletor de eventos.  
  
 ATL fornece vários macros, [BEGIN\_SINK\_MAP](../Topic/BEGIN_SINK_MAP.md), [END\_SINK\_MAP](../Topic/END_SINK_MAP.md), e [SINK\_ENTRY\_EX](../Topic/SINK_ENTRY.md), que facilitam esse mapeamento.  O formato padrão é:  
  
 `BEGIN_SINK_MAP(comClass)`  
  
 `SINK_ENTRY_EX(id, iid, dispid, func)`  
  
 `.  .  .  //additional external event entries`  
  
 `END_SINK_MAP()`  
  
 O seguinte exemplo declara um mapa do coletor de eventos com dois manipuladores de eventos:  
  
 [!code-cpp[NVC_ATL_Windowing#136](../atl/codesnippet/CPP/supporting-idispeventimpl_3.h)]  
  
 A implementação é quase concluído.  A última etapa refere\-se ao do unadvising e conselhos interfaces externos.  
  
## Conselhos Unadvising e interfaces de IDispEventImpl  
 A etapa final é implementar um método que seja recomendável \(ou\) unadvise todos os pontos de conexão no momento apropriado.  Isso recomendável que deve ser feito antes de comunicação entre os clientes externos e seu objeto pode ocorrer.  Antes de seu objeto se torne visível, cada interface externo de distribuição suportada pelo objeto é consultada para interfaces de saída.  Uma conexão é estabelecida e uma referência para a interface de saída é usada para manipular eventos do objeto.  Este procedimento é conhecido como “recomendando”.  
  
 Após o objeto terminar com as interfaces externos, as interfaces de saída devem ser notificados que não são usadas por sua classe.  Esse processo é conhecido como “unadvising”.  
  
 Devido a natureza exclusivo de objetos COM, este procedimento varia, em detalhes e execução, entre implementações.  Esses detalhes são além do escopo de este tópico e não são endereçados.  
  
## Consulte também  
 [Fundamentos de objetos COM de ATL](../atl/fundamentals-of-atl-com-objects.md)