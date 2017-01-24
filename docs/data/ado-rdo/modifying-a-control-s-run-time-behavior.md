---
title: "Modificando o comportamento de tempo de execu&#231;&#227;o de um controle | Microsoft Docs"
ms.custom: ""
ms.date: "12/03/2016"
ms.prod: "visual-studio-dev14"
ms.reviewer: ""
ms.suite: ""
ms.technology: 
  - "devlang-cpp"
ms.tgt_pltfrm: ""
ms.topic: "article"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "Controles ActiveX [C++], o comportamento de tempo de execução"
ms.assetid: 78b44b0f-0d5a-4da0-8aa2-595f5789c634
caps.latest.revision: 10
caps.handback.revision: 10
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# Modificando o comportamento de tempo de execu&#231;&#227;o de um controle
[!INCLUDE[vs2017banner](../../assembler/inline/includes/vs2017banner.md)]

Depois que você [Inserir um controle](../../data/ado-rdo/inserting-the-control-into-a-visual-cpp-application.md) e gerar um ou mais [classes wrapper](../../data/ado-rdo/wrapper-classes.md), você pode chamar os métodos do controle e manipuladores de eventos do controle do programa.  
  
 O controle [classes wrapper](../../data/ado-rdo/wrapper-classes.md) especificar as funções que você pode usar para modificar o comportamento de tempo de execução do controle. Incluir o arquivo de cabeçalho de classe de wrapper apropriado e usar os métodos. Para definir uma propriedade, procure por um método do acessador com o nome da propriedade prefixado pelo conjunto. Para recuperar uma propriedade, procure por um método do acessador com o nome da propriedade Get o prefixo. Manipuladores de eventos podem ser gravados posteriormente.  
  
 Como os controles são implementados usando a automação, os tipos passados só podem ser tipos de automação safe como BSTR e VARIANTE. Embora seja possível usar as chamadas do sistema para alocar e definir BSTRs e variantes, você talvez queira usar as classes de wrapper do ATL \([CComBSTR](../../atl/reference/ccombstr-class.md), [CComVariant](../../atl/reference/ccomvariant-class.md)\), as classes de wrapper do compilador do Visual C\+\+ COM suporte \([bstr\_t](../../cpp/bstr-t-class.md), [variant\_t](../../cpp/variant-t-class.md)\), ou a classe de wrapper MFC \([COleVariant](../../mfc/reference/colevariant-class.md)\).  
  
 Se você adicionar um controle de dados, o Assistente para inserir controle ActiveX gera classes de wrapper para coclasses do controle de dados que gerenciam seus objetos de dados internos. Essas classes não incluir todas RDO ou ADO, mas em vez disso, representam declarados na biblioteca de tipos de objetos internos.  
  
 Se você quiser usar o ADO e RDO diretamente, você deve conectar o ADO ou os DLLs RDO diretamente \(Msado15 ou MSRDO20. dll\), ou com o [classes de suporte COM do compilador](../../cpp/compiler-com-support-classes.md), que oferecem suporte a [\#import diretiva](../../preprocessor/preprocessor-directives.md), ou com o SDK do respectivo.  
  
## Para definir propriedades de controle em tempo de execução  
 Observe que algumas propriedades de um controle ActiveX podem ser somente leitura em tempo de execução, o que dificulta a criação dinâmica. Você pode simular temporariamente o modo de design para a inicialização de propriedade, substituindo o contêiner de controle [OnAmbientPropertyChange](../Topic/COleControl::OnAmbientPropertyChange.md) manipulador, conforme descrito no artigo da Base de dados de Conhecimento, "como: definir propriedades de tempo de Design do controle ActiveX em tempo de execução \(Q260744\)". Você pode encontrar artigos da Base de dados de conhecimento em [http:\/\/support.microsoft.com\/](http://support.microsoft.com/).  
  
## Consulte também  
 [Usando controles ActiveX](../Topic/Using%20ActiveX%20Controls.md)