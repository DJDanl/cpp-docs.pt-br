---
title: Definindo funções C++ embutidas com dllexport e dllimport | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-language
ms.topic: language-reference
dev_langs:
- C++
helpviewer_keywords:
- inline functions [C++], defining
- functions [C++], defining inline
- dllimport attribute [C++], inline functions
- dllexport attribute [C++], inline functions
ms.assetid: 3b48678b-e7b8-4eda-bb46-b5d34dcf7817
author: mikeblome
ms.author: mblome
ms.workload:
- cplusplus
ms.openlocfilehash: 027b7a78f46d2bd9fce6ed55b089da1517124da0
ms.sourcegitcommit: 2b9e8af9b7138f502ffcba64e2721f7ef52af23b
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 08/01/2018
ms.locfileid: "39407326"
---
# <a name="defining-inline-c-functions-with-dllexport-and-dllimport"></a>Definindo funções embutidas do C++ com dllexport e dllimport
## <a name="microsoft-specific"></a>Específico da Microsoft  
 Você pode definir como embutida uma função com o **dllexport** atributo. Nesse caso, a função sempre é instanciada e exportada, mesmo se qualquer módulo no programa fizer referência à função. Presume-se que a função seja importada por outro programa.  
  
 Você também pode definir como embutida uma função declarada com o atributo **dllimport**. Nesse caso, a função pode ser expandida (sujeito às especificações de /Ob), mas nunca instanciada. Em particular, se o endereço de uma função importada embutida for usado, o endereço da função que reside na DLL será retornado. Esse comportamento é o mesmo que usar o endereço de uma função importada não embutida.  
  
 Essas regras se aplicam às funções embutidas cujas definições aparecem dentro de uma definição de classe. Além disso, os dados locais estáticos e as cadeias de caracteres em funções embutidas mantêm as mesmas identidades entre a DLL e o cliente como em um único programa (isto é, um arquivo executável sem uma interface de DLL).  
  
 Tenha cuidado ao fornecer funções embutidas importadas. Por exemplo, se você atualizar a DLL, não suponha que o cliente não usará a versão modificada da DLL. Para garantir que você esteja carregando a versão apropriada da DLL, recompile o cliente da DLL também.  
  
**Fim da seção específica da Microsoft**  
  
## <a name="see-also"></a>Consulte também  
 [dllexport, dllimport](../cpp/dllexport-dllimport.md)