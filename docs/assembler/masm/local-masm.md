---
title: LOCAL (MASM)
ms.date: 08/30/2018
f1_keywords:
- Local
helpviewer_keywords:
- LOCAL directive
ms.assetid: 76147e2d-23ca-4f1e-8817-81428becd113
ms.openlocfilehash: c3a04f68b7fd17b2b6459c219a98fd99ec2d62d4
ms.sourcegitcommit: 9ee5df398bfd30a42739632de3e165874cb675c3
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 11/22/2019
ms.locfileid: "74397249"
---
# <a name="local-masm"></a>LOCAL (MASM)

Na primeira diretiva, em uma macro, **local** define os rótulos que são exclusivos de cada instância da macro.

## <a name="syntax"></a>Sintaxe

> ⟦ *LocalName* **local** , *LocalName* ... ⟧
>
> *Rótulo* local ⟦ __\[__ *contagem* __]__ ⟧ ⟦ __:__ *tipo*⟧ ⟦ __,__ *rótulo* ⟦ __\[__ *contagem* __]__ ⟧ ⟦*tipo*⟧... ⟧

## <a name="remarks"></a>Comentários

Na segunda diretiva, dentro de uma definição de procedimento (**proc**), o **local** cria variáveis baseadas em pilha que existem para a duração do procedimento. O *rótulo* pode ser uma variável simples ou uma matriz que contenha elementos de *contagem* .

## <a name="see-also"></a>Consulte também

[Referência de diretivas](directives-reference.md)
