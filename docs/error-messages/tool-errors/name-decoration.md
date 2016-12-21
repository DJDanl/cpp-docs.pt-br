---
title: "Decora&#231;&#227;o do nome | Microsoft Docs"
ms.custom: ""
ms.date: "12/03/2016"
ms.prod: "visual-studio-dev14"
ms.reviewer: ""
ms.suite: ""
ms.technology: 
  - "devlang-cpp"
ms.tgt_pltfrm: ""
ms.topic: "error-reference"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "nomes decorados, convenções de chamada"
  - "decoração de nome [C++]"
  - "nomes [C++], decorado"
ms.assetid: 8327a27b-bb4f-49f2-8218-b851b9d2a463
caps.latest.revision: 9
caps.handback.revision: 9
author: "corob-msft"
ms.author: "corob"
manager: "ghogen"
---
# Decora&#231;&#227;o do nome
[!INCLUDE[vs2017banner](../../assembler/inline/includes/vs2017banner.md)]

Decoração de nome geralmente se refere a convenções de nomenclatura do C\+\+, mas pode ser aplicadas a um número de casos de C também.  Por padrão, o C\+\+ usa o nome da função, parâmetros e tipo de retorno para criar um nome de vinculador para a função.  Considere a seguinte função:  
  
```  
void CALLTYPE test(void)  
```  
  
 A tabela a seguir mostra o nome do vinculador para várias convenções de chamada.  
  
|Convenção de chamada|extern "C" ou. c arquivo|. cpp,. cxx ou \/TP|  
|--------------------------|------------------------------|-------------------------|  
|Convenção de nomenclatura de C \(`__cdecl`\)|testar|? test@@ZAXXZ|  
|Convenção de nomenclatura fastcall \(`__fastcall`\)|@test@ 0|? test@@YIXXZ|  
|Convenção de nomenclatura padrão de chamada \(`__stdcall`\)|\_test@0|? test@@YGXXZ|  
|Convenção de nomenclatura Vectorcall \(`__vectorcall`\)|Test@@0|? test@@YQXXZ|  
  
 Use extern "C" para chamar uma função C de C\+\+.  Extern "C" força o uso da convenção de nomenclatura de C para funções de C\+\+ não seja da classe.  Lembre\-se de comutadores de compilador **\/Tc** ou **\/Tp**, que instrui o compilador a ignorar a extensão de nome de arquivo e compilar o arquivo como C ou C\+\+, respectivamente.  Essas opções podem causar nomes que você não espera.  
  
 Ter protótipos de função que têm parâmetros incompatíveis também pode causar esse erro.  Decoração de nome incorpora o nome decorado de função final os parâmetros de uma função.  Chamando uma função com os tipos de parâmetro que não coincidem com aqueles na declaração de função também pode causar LNK2001.  
  
 Atualmente, há um padrão de nomeação entre fornecedores de compilador ou até mesmo entre versões diferentes de um compilador de C\+\+.  Arquivos de objeto compilados com outros compiladores de vinculação, portanto, talvez não produza o mesmo esquema de nomenclatura e, portanto, faz com que externos não resolvidos.  
  
## Consulte também  
 [Erro das Ferramentas de Vinculador LNK2001](../Topic/Linker%20Tools%20Error%20LNK2001.md)