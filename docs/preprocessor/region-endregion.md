---
title: "region, endregion | Microsoft Docs"
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
  - "vc-pragma.endregion"
  - "endregion_CPP"
  - "region_CPP"
  - "vc-pragma.region"
dev_langs: 
  - "C++"
  - "C"
helpviewer_keywords: 
  - "pragma endregion"
  - "pragmas, endregion"
  - "pragmas, região"
  - "pragma de região"
ms.assetid: c697f807-622f-4796-851b-68a42bbecd84
caps.latest.revision: 7
caps.handback.revision: 7
author: "corob-msft"
ms.author: "corob"
manager: "ghogen"
---
# region, endregion
[!INCLUDE[vs2017banner](../assembler/inline/includes/vs2017banner.md)]

**\#pragma region** permite que você especifique um bloco de código que você pode expandir ou recolher ao usar o [recurso de estrutura de tópicos](../Topic/Outlining.md) do editor de códigos do Visual Studio.  
  
## Sintaxe  
  
```  
#pragma region name  
#pragma endregion comment  
```  
  
#### Parâmetros  
 `comment`\(opcional\)  
 Um comentário será exibido no editor de códigos.  
  
 *nome*\(opcional\)  
 O nome da região.  Esse nome será exibido no editor de códigos.  
  
## Comentários  
 **\#pragma endregion** marca o fim de um bloco **\#pragma region**.  
  
 Um bloco `#region` deve terminar com **\#pragma endregion**.  
  
## Exemplo  
  
```  
// pragma_directives_region.cpp  
#pragma region Region_1  
void Test() {}  
void Test2() {}  
void Test3() {}  
#pragma endregion Region_1  
  
int main() {}  
```  
  
## Consulte também  
 [Diretivas Pragma e a palavra\-chave \_\_Pragma](../preprocessor/pragma-directives-and-the-pragma-keyword.md)