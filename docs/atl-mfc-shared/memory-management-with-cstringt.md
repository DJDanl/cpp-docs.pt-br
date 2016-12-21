---
title: "Gerenciamento de mem&#243;ria com CStringT | Microsoft Docs"
ms.custom: ""
ms.date: "12/03/2016"
ms.prod: "visual-studio-dev14"
ms.reviewer: ""
ms.suite: ""
ms.technology: 
  - "devlang-cpp"
ms.tgt_pltfrm: ""
ms.topic: "reference"
f1_keywords: 
  - "CStringT"
  - "ATL::CStringT"
  - "ATL.CStringT"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "Classe de CFixedStringT, descrição de"
  - "Objetos de CString, gerenciamento de memória"
  - "Classe de CStringT, gerenciamento de memória"
  - "Classe de IAtlStringMgr, Usando"
  - "memória [C++], uso"
  - "cadeias de caracteres [C++], gerenciamento de memória personalizado"
  - "cadeias de caracteres [C++], gerenciamento de memória"
ms.assetid: 88b8342d-19b5-48c4-9cf6-e4c44cece21e
caps.latest.revision: 10
caps.handback.revision: 6
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# Gerenciamento de mem&#243;ria com CStringT
[!INCLUDE[vs2017banner](../assembler/inline/includes/vs2017banner.md)]

A classe [CStringT](../atl-mfc-shared/reference/cstringt-class.md) é uma classe de modelo usada para manipular cadeias de caracteres de comprimento variável.  A memória para armazenar estas cadeias de caracteres é atribuída e liberada através de um objeto do gerenciador de cadeia de caracteres, associado com cada instância de `CStringT`.  O MFC e fornecem as ATL instanciações padrão de `CStringT`, de `CString`chamado, de `CStringA`, e de `CStringW`, que manipulem cadeias de caracteres de tipos de caracteres diferentes.  Esses tipos de caracteres são do tipo **TCHAR**, `char`, e `wchar_t`, respectivamente.  Esses tipos padrão de cadeia de caracteres usam um gerente de cadeia de caracteres que atribui a memória do heap de processo \(em ATL\) ou no heap do CRT \(no MFC\).  Para aplicativos típicos, este esquema de alocação de memória é suficiente.  Em o entanto, como código que fazem uso intensivo de cadeias de caracteres \(multithreaded\) ou código que os gerentes de memória padrão não podem executar ideal.  Este tópico descreve como substituir o comportamento padrão de gerenciamento de memória de `CStringT`, criando os distribuidores otimizados especificamente para a tarefa manualmente.  
  
-   [Implementação de um gerente personalizado de cadeia de caracteres \(básico método\)](../atl-mfc-shared/implementation-of-a-custom-string-manager-basic-method.md)  
  
-   [Prevenção de conflito da heap](../atl-mfc-shared/avoidance-of-heap-contention.md)  
  
-   [Implementação de um gerente personalizado de cadeia de caracteres \(método poderoso\)](../Topic/Implementation%20of%20a%20Custom%20String%20Manager%20\(Advanced%20Method\).md)  
  
-   [CFixedStringT: Um exemplo de um gerente personalizado de cadeia de caracteres](../atl-mfc-shared/cfixedstringt-example-of-a-custom-string-manager.md)  
  
## Consulte também  
 [exemplo de CustomString](../top/visual-cpp-samples.md)