---
title: Contextos de atributo | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-windows
ms.topic: reference
dev_langs:
- C++
helpviewer_keywords:
- attributes [C++], contexts
ms.assetid: 3086351f-77a8-4048-99e9-3b6b041b9437
author: mikeblome
ms.author: mblome
ms.workload:
- cplusplus
- uwp
ms.openlocfilehash: 7635f49a494648f18bcd59eb8d212cc76d1f1539
ms.sourcegitcommit: 6f8dd98de57bb80bf4c9852abafef1c35a7600f1
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 08/22/2018
ms.locfileid: "42600794"
---
# <a name="attribute-contexts"></a>Contextos de atributo
Atributos de C++ podem ser descritos usando quatro campos básicos: o destino podem ser aplicadas a (**aplica-se a**), se eles são repetidos ou não (**Repeatable**), o necessário a presença de outros atributos ( **Atributos necessários**) e incompatibilidades com outros atributos (**atributos inválidos**). Esses campos são listados em uma tabela que acompanha este artigo no tópico de referência do cada atributo. Cada um desses campos é descrita abaixo.
  
## <a name="applies-to"></a>Aplica-se a
 Esse campo descreve os diferentes elementos de linguagem C++ que são destinos válidos para o atributo especificado. Por exemplo, se um atributo especifica "class" no **aplica-se a** campo, isso indica que o atributo só pode ser aplicado a uma classe C++ legal. Se o atributo é aplicado a uma função de membro de uma classe, isso resultaria em um erro de sintaxe.
  
 Para obter mais informações, consulte [atributos por uso](../windows/attributes-by-usage.md).
  
## <a name="repeatable"></a>Repetível
 Este campo indica se o atributo pode ser aplicado várias vezes para o mesmo destino. A maioria dos atributos não são repetidas.
  
## <a name="required-attributes"></a>Atributos obrigatórios
 Esse campo lista outros atributos que precisam estar presentes (ou seja, aplicada para o mesmo destino) para o atributo especificado funcionar corretamente. É incomum para um atributo ter todas as entradas para esse campo.
  
## <a name="invalid-attributes"></a>Atributos inválidos
 Esse campo lista outros atributos que são incompatíveis com o atributo especificado. É incomum para um atributo ter todas as entradas para esse campo.
  
## <a name="see-also"></a>Consulte também
 [Referência de atributos do C++](../windows/cpp-attributes-reference.md)