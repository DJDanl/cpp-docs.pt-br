---
title: 'Como: alterar o idioma ou a condição de um recurso durante a cópia (C++) | Microsoft Docs'
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-windows
ms.topic: conceptual
f1_keywords:
- vc.resvw.resource.changing
dev_langs:
- C++
helpviewer_keywords:
- Language property [C++]
ms.assetid: 8f622ab0-bac2-468f-ae70-78911afc4759
author: mikeblome
ms.author: mblome
ms.workload:
- cplusplus
- uwp
ms.openlocfilehash: 3594e3c6ec839e41963ba7458e246563241bb4aa
ms.sourcegitcommit: a9dcbcc85b4c28eed280d8e451c494a00d8c4c25
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 10/25/2018
ms.locfileid: "50066559"
---
# <a name="how-to-change-the-language-or-condition-of-a-resource-while-copying-c"></a>Como: alterar o idioma ou a condição de um recurso durante a cópia (C++)

Durante a cópia em um recurso, você pode alterar sua propriedade de idioma ou a propriedade de condição ou ambos.

- O idioma do recurso identifica exatamente isso, o idioma para o recurso. Isso é usado pelo [FindResource](/windows/desktop/api/winbase/nf-winbase-findresourcea) para ajudar a identificar o recurso para o qual você está procurando. (No entanto, recursos podem ter diferenças para cada idioma que não estão relacionados ao texto, por exemplo, aceleradores que podem funcionar apenas em um teclado japonês ou um bitmap que só podem ser apropriado para chinês localizadas compilações, etc.)

- A condição de um recurso é um símbolo definido que identifica uma condição sob a qual essa cópia particular do recurso deve ser usado.

O idioma e a condição de um recurso são mostrados entre parênteses após o nome do recurso na janela do espaço de trabalho. Neste exemplo o recurso denominado IDD_AboutBox e estiver usando finlandês como sua linguagem de sua condição XX33.

```cpp
IDD_AboutBox (Finnish - XX33)
```

### <a name="to-copy-an-existing-resource-and-change-its-language-or-condition"></a>Para copiar um recurso existente e alterar seu idioma ou uma condição

1. No arquivo. rc ou na [exibição de recurso](../windows/resource-view-window.md) janela, clique com botão direito o recurso que você deseja copiar.

2. Escolher **inserir cópia** no menu de atalho.

3. No **inserir cópia do recurso** caixa de diálogo:

   - Para o **linguagem** caixa de listagem, selecione o idioma.

   - No **condição** , digite a condição.

## <a name="requirements"></a>Requisitos

Win32

## <a name="see-also"></a>Consulte também

[Como copiar recursos](../windows/how-to-copy-resources.md)<br/>
[Arquivos de recurso](../windows/resource-files-visual-studio.md)<br/>
[Editores de recursos](../windows/resource-editors.md)