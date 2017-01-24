---
title: "Definindo fun&#231;&#245;es C++ embutidas com dllexport e dllimport | Microsoft Docs"
ms.custom: ""
ms.date: "12/03/2016"
ms.prod: "visual-studio-dev14"
ms.reviewer: ""
ms.suite: ""
ms.technology: 
  - "devlang-cpp"
ms.tgt_pltfrm: ""
ms.topic: "language-reference"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "atributo dllexport [C++], funções embutidas"
  - "Atributo dllimport [C++], funções embutidas"
  - "funções [C++], definindo embutido"
  - "funções embutidas [C++], definindo"
ms.assetid: 3b48678b-e7b8-4eda-bb46-b5d34dcf7817
caps.latest.revision: 7
caps.handback.revision: 7
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# Definindo fun&#231;&#245;es C++ embutidas com dllexport e dllimport
[!INCLUDE[vs2017banner](../assembler/inline/includes/vs2017banner.md)]

## Específico da Microsoft  
 Você pode definir como uma função embutida com o atributo `dllexport`.  Nesse caso, a função sempre é instanciada e exportada, mesmo se qualquer módulo no programa fizer referência à função.  Presume\-se que a função seja importada por outro programa.  
  
 Você também pode definir como uma função declarada com o atributo **dllimport**.  Nesse caso, a função pode ser expandida \(sujeito às especificações de \/Ob\), mas nunca instanciada.  Em particular, se o endereço de uma função importada embutida for usado, o endereço da função que reside na DLL será retornado.  Esse comportamento é o mesmo que usar o endereço de uma função importada não embutida.  
  
 Essas regras se aplicam às funções embutidas cujas definições aparecem dentro de uma definição de classe.  Além disso, os dados locais estáticos e as cadeias de caracteres em funções embutidas mantêm as mesmas identidades entre a DLL e o cliente como em um único programa \(isto é, um arquivo executável sem uma interface de DLL\).  
  
 Tenha cuidado ao fornecer funções embutidas importadas.  Por exemplo, se você atualizar a DLL, não suponha que o cliente não usará a versão modificada da DLL.  Para garantir que você esteja carregando a versão apropriada da DLL, recompile o cliente da DLL também.  
  
## FIM de Específico da Microsoft  
  
## Consulte também  
 [dllexport, dllimport](../cpp/dllexport-dllimport.md)