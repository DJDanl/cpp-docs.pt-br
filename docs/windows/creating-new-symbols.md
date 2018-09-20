---
title: Criando novos símbolos | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-windows
ms.topic: conceptual
f1_keywords:
- vc.editors.symbol.creating
dev_langs:
- C++
helpviewer_keywords:
- New Symbol dialog box [C++]
- symbols [C++], creating
ms.assetid: 35168d31-3af6-4ecd-9362-3707d47b53f3
author: mikeblome
ms.author: mblome
ms.workload:
- cplusplus
- uwp
ms.openlocfilehash: 156f5979cb27b18247c63f177fa036aa3eeabb79
ms.sourcegitcommit: 799f9b976623a375203ad8b2ad5147bd6a2212f0
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 09/19/2018
ms.locfileid: "46412113"
---
# <a name="creating-new-symbols"></a>Criando novos símbolos

Quando você inicia um novo projeto, talvez seja conveniente para mapear os nomes de símbolo que você precisa antes de criar os recursos ao qual serão atribuídos.

### <a name="to-create-a-new-symbol-using-the-resource-symbols-dialog-box"></a>Para criar um novo símbolo usando a caixa de diálogo de símbolos de recurso

1. No [caixa de diálogo símbolos de recurso](../windows/resource-symbols-dialog-box.md), escolha **New**.

2. No **nome** , digite um nome de símbolo.

3. Aceite o valor atribuído de símbolo.

   -ou-

   No **valor** , digite um novo valor.

4. Clique em **Okey** para adicionar o novo símbolo à lista de símbolos.

Se você digitar um nome de símbolo que já existe, uma caixa de mensagem será exibida, informando que um símbolo com este nome já está definido. Não é possível definir duas ou mais símbolos com o mesmo nome, mas você pode definir símbolos diferentes com o mesmo valor numérico. Para obter mais informações, consulte [restrições de nome de símbolo](../windows/symbol-name-restrictions.md) e [restrições de valor de símbolo](../windows/symbol-value-restrictions.md).

Para obter informações sobre como adicionar recursos a projetos gerenciados, consulte [recursos em aplicativos de área de trabalho](/dotnet/framework/resources/index) na *guia do desenvolvedor do .NET Framework*. Para obter informações sobre como adicionar manualmente os arquivos de recurso a projetos gerenciados, acessar recursos, exibir recursos estáticos e atribuir recursos cadeias de caracteres de propriedades.

## <a name="requirements"></a>Requisitos

Win32

## <a name="see-also"></a>Consulte também

[Exibindo símbolos de recurso](../windows/viewing-resource-symbols.md)<br/>
[IDs de símbolos predefinidos](../windows/predefined-symbol-ids.md)