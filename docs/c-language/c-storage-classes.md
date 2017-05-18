---
title: Classes de Armazenamento C | Microsoft Docs
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
- static variables, lifetime
- storage classes
- lifetime, variables
- specifiers, storage class
- storage class specifiers, C storage classes
- storage duration
ms.assetid: 893fb929-f7a9-43dc-a0b3-29cb1ef845c1
caps.latest.revision: 9
author: mikeblome
ms.author: mblome
manager: ghogen
translation.priority.ht:
- cs-cz
- de-de
- es-es
- fr-fr
- it-it
- ja-jp
- ko-kr
- pl-pl
- pt-br
- ru-ru
- tr-tr
- zh-cn
- zh-tw
ms.translationtype: Human Translation
ms.sourcegitcommit: a937c9d083a7e4331af63323a19fb207142604a0
ms.openlocfilehash: d1373ae6cdade4dbe038fc313cf46ac7bb81bf42
ms.contentlocale: pt-br
ms.lasthandoff: 02/25/2017

---
# <a name="c-storage-classes"></a>Classes de armazenamento C
A "classe de armazenamento" de uma variável determina se o item tem um tempo de vida “global” ou “local”. C chama esse dois tempos de vida de “estático” e “automático”. Um item com um tempo de vida global existe e tem um valor durante toda a execução do programa. Todas as funções têm tempos de vida globais.  
  
 As variáveis automáticas, ou variáveis com tempo de vida local, recebem novos armazenamentos cada vez que o controle de execução é transmitido para o bloco no qual elas são definidas. Quando a execução retornar, as variáveis não terão mais valores significativos.  
  
 C fornece os seguintes especificadores de classe de armazenamento:  
  
## <a name="syntax"></a>Sintaxe  
 *storage-class-specifier*:  
 **auto**  
  
 **register**  
  
 **static**  
  
 **extern**  
  
 **typedef**  
  
 **__declspec** ( *extended-decl-modifier-seq* ) /* Específico da Microsoft \*/  
  
 Com exceção de `__declspec`, você pode usar somente um *storage-class-specifier* no *declaration-specifier* em uma declaração. Se nenhuma especificação de classe de armazenamento for feita, as declarações de um bloco criarão objetos automáticos.  
  
 Os itens declarados com o especificador **auto** ou **register** têm tempos de vida locais. Os itens declarados com o especificador **static** ou `extern` têm tempos de vida globais.  
  
 Como `typedef` e `__declspec` são semanticamente diferentes dos outros quatro terminais *storage-class-specifier*, eles são discutidos separadamente. Para obter informações específicas sobre `typedef`, consulte [Declarações typedef](../c-language/typedef-declarations.md). Para obter informações específicas sobre `__declspec`, consulte [Atributos de classe de armazenamento estendidos](../c-language/c-extended-storage-class-attributes.md).  
  
 O posicionamento de declarações de variável e de função em arquivos de origem também afeta a classe e a visibilidade de armazenamento. As declarações fora de todas as definições de função devem aparecer no "nível externo". As declarações em definições de função aparecem no "nível interno".  
  
 O significado exato de cada especificador de classe de armazenamento depende de dois fatores:  
  
-   Se a declaração aparece no nível externo ou interno  
  
-   Se o item que está sendo declarado é uma variável ou uma função  
  
 [Especificadores de classe de armazenamento para declarações de nível externo](../c-language/storage-class-specifiers-for-external-level-declarations.md) e [Especificadores de classe de armazenamento para declarações de nível interno](../c-language/storage-class-specifiers-for-internal-level-declarations.md) descrevem os terminais *storage-class-specifier* em cada tipo de declaração e explicam o comportamento padrão quando o *storage-class-specifier* é omitido de uma variável. [Especificadores de classe de armazenamento com declarações de função](../c-language/storage-class-specifiers-with-function-declarations.md) discutem os especificadores de classe de armazenamento usados com as funções.  
  
## <a name="see-also"></a>Consulte também  
 [Declarações e tipos](../c-language/declarations-and-types.md)
