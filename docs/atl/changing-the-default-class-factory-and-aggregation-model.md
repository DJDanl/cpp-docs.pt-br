---
title: "Modificando o modelo padr&#227;o de f&#225;brica e de distribui&#231;&#227;o de classe | Microsoft Docs"
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
  - "agregação [C++], modelos de agregação"
  - "agregação [C++], usando ATL"
  - "Classe de CComClassFactory, fazendo a opção"
  - "Classe de CComCoClass, fábrica padrão da classe e modelo de agregação"
  - "fábricas de classe, alterando a opção"
  - "fábrica de classe padrão"
  - "fábrica de classe padrão, ATL"
  - "opções [C++], modelo de agregação em ATL"
  - "opções [C++], fábrica de classe"
ms.assetid: 6e040e95-0f38-4839-8a8b-c9800dd47e8c
caps.latest.revision: 11
caps.handback.revision: 6
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# Modificando o modelo padr&#227;o de f&#225;brica e de distribui&#231;&#227;o de classe
[!INCLUDE[vs2017banner](../assembler/inline/includes/vs2017banner.md)]

Usos [CComCoClass](../Topic/CComCoClass%20Class.md) de ATL definir o factory e a agregação padrão da classe padrão para o objeto.  `CComCoClass` especifica os dois seguintes macros:  
  
-   [DECLARE\_CLASSFACTORY](../Topic/DECLARE_CLASSFACTORY.md) declara o factory da classe para ser [CComClassFactory](../atl/reference/ccomclassfactory-class.md).  
  
-   [DECLARE\_AGGREGATABLE](../Topic/DECLARE_AGGREGATABLE.md) declara que o objeto pode ser agregado.  
  
 Você pode substituir qualquer uma de essas opções especificando outro macro em sua definição de classe.  Por exemplo, para usar [CComClassFactory2](../Topic/CComClassFactory2%20Class.md) em vez de `CComClassFactory`, especifique a macro de [DECLARE\_CLASSFACTORY2](../Topic/DECLARE_CLASSFACTORY2.md) :  
  
 [!code-cpp[NVC_ATL_COM#2](../atl/codesnippet/CPP/changing-the-default-class-factory-and-aggregation-model_1.h)]  
  
 Outros dois macros que definem uma fábrica de classe são [DECLARE\_CLASSFACTORY\_AUTO\_THREAD](../Topic/DECLARE_CLASSFACTORY_AUTO_THREAD.md) e [DECLARE\_CLASSFACTORY\_SINGLETON](../Topic/DECLARE_CLASSFACTORY_SINGLETON.md).  
  
 ATL também usa o mecanismo de `typedef` para implementar o comportamento padrão.  Por exemplo, a macro de `DECLARE_AGGREGATABLE` usa `typedef` para definir um tipo chamado **\_CreatorClass**, que é referenciado em todo ATL.  Observe que em uma classe derivada, `typedef` usando o mesmo nome que os resultados de `typedef` de classe de base em ATL usando sua definição e substituindo o comportamento padrão.  
  
## Consulte também  
 [Fundamentos de objetos COM de ATL](../atl/fundamentals-of-atl-com-objects.md)   
 [Macros de fábrica de distribuição e uma classe](../atl/reference/aggregation-and-class-factory-macros.md)