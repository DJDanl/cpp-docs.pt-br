---
title: "Definindo funções C embutidas com dllexport e dllimport | Microsoft Docs"
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- cpp-language
ms.tgt_pltfrm: 
ms.topic: article
dev_langs:
- C++
helpviewer_keywords:
- inline functions [C++], with dllexport and dllimport
- dllimport attribute [C++], inline functions
- dllexport attribute [C++], inline functions
- dllexport attribute [C++]
ms.assetid: 41418f7c-1c11-470b-bb2e-1f8269a239f0
caps.latest.revision: 
author: mikeblome
ms.author: mblome
manager: ghogen
ms.workload:
- cplusplus
ms.openlocfilehash: a20ff9e120b8e71536be6a989351df74d2e2c2e5
ms.sourcegitcommit: 8fa8fdf0fbb4f57950f1e8f4f9b81b4d39ec7d7a
ms.translationtype: HT
ms.contentlocale: pt-BR
ms.lasthandoff: 12/21/2017
---
# <a name="defining-inline-c-functions-with-dllexport-and-dllimport"></a>Definindo funções C embutidas com dllexport e dllimport
**Seção específica da Microsoft**  
  
 Você pode definir como uma função embutida com o atributo `dllexport`. Nesse caso, a função sempre é instanciada e exportada, mesmo se qualquer módulo no programa fizer referência à função. Presume-se que a função seja importada por outro programa.  
  
 Você também pode definir como embutida uma função declarada com o atributo **dllimport**. Nesse caso, a função pode ser expandida (sujeito à especificação da opção do compilador /Ob (embutido)), mas nunca instanciada. Em particular, se o endereço de uma função importada embutida for usado, o endereço da função que reside na DLL será retornado. Esse comportamento é o mesmo que usar o endereço de uma função importada não embutida.  
  
 Os dados locais estáticos e as cadeias de caracteres em funções embutidas mantêm as mesmas identidades entre a DLL e o cliente como em um único programa (isto é, um arquivo executável sem uma interface de DLL).  
  
 Tenha cuidado ao fornecer funções embutidas importadas. Por exemplo, se você atualizar a DLL, não suponha que o cliente não usará a versão modificada da DLL. Para garantir que você esteja carregando a versão apropriada da DLL, recompile o cliente da DLL também.  
  
 **Fim da seção específica da Microsoft**  
  
## <a name="see-also"></a>Consulte também  
 [Funções de importação e exportação de DLL](../c-language/dll-import-and-export-functions.md)