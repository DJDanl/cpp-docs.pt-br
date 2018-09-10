---
title: 'Como: abrir um arquivo de Script de recurso no formato de texto (C++) | Microsoft Docs'
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-windows
ms.topic: conceptual
f1_keywords:
- vc.editors.resource
dev_langs:
- C++
helpviewer_keywords:
- resource script files [C++], opening in text format
- .rc files [C++], opening in text format
- rc files [C++], opening in text format
ms.assetid: 0bc57527-f53b-40c9-99a9-4dcbc5c9af57
author: mikeblome
ms.author: mblome
ms.workload:
- cplusplus
- uwp
ms.openlocfilehash: 2c2f73c77e86a2b23213b3b6aabdd0bc85f91586
ms.sourcegitcommit: f0c90000125a9497bf61e41624de189a043703c0
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 09/10/2018
ms.locfileid: "44317063"
---
# <a name="how-to-open-a-resource-script-file-in-text-format"></a>Como abrir o arquivo de script do recurso no formato de texto

Pode haver ocasiões quando desejar exibir o conteúdo do arquivo de script (. rc) do recurso do seu projeto sem abrir um recurso, como uma caixa de diálogo dentro do seu editor de recurso específico. Por exemplo, você talvez queira procurar uma cadeia de caracteres em todas as caixas de diálogo no arquivo de recurso sem precisar abrir cada um deles separadamente.

> [!NOTE]
> Se seu projeto já não contiver um arquivo. RC, consulte [criando um novo arquivo de Script de recurso](../windows/how-to-create-a-resource-script-file.md).

Você pode abrir facilmente o arquivo de recurso no formato de texto para exibir todos os recursos que ele contém e executem operações globais com suporte pelo editor de texto.

> [!NOTE]
> Os editores de recursos não ler diretamente. rc ou `resource.h` arquivos. O compilador de recurso compila-os em arquivos de .aps, que são consumidos pelos editores de recursos. Esse arquivo é uma etapa de compilação e armazena apenas dados simbólicos. Como com um normal de processo de compilação, as informações que não seja simbólicas (por exemplo, comentários) são descartadas durante o processo de compilação. Sempre que o arquivo .aps obtém fora de sincronia com o arquivo. RC, o arquivo. rc for gerado novamente (por exemplo, quando você salva, o editor de recurso substitui o arquivo. RC e o arquivo Resource h). Todas as alterações para os próprios recursos permanecerão incorporadas no arquivo. RC, mas comentários sempre serão perdidos depois que o arquivo. RC é substituído. Para obter informações sobre como preservar comentários, consulte [incluindo recursos em tempo de compilação](../windows/how-to-include-resources-at-compile-time.md).

### <a name="to-open-a-resource-script-file-as-text"></a>Para abrir um arquivo de script de recurso como texto

1. Do **arquivo** menu escolha **aberto**, em seguida, clique em **arquivo.**

2. No **abrir arquivo** caixa de diálogo, navegue até o arquivo de script de recurso que você deseja exibir no formato de texto.

3. Realce o arquivo e, em seguida, clique na seta suspensa na **abrir** botão (localizado à direita do botão).

4. Escolher **abrir com** no menu suspenso.

5. No **abrir com** caixa de diálogo, clique em **Editor de código-fonte (texto)**.

6. Dos **abrir como** lista suspensa, selecione **texto**.

   O recurso é aberto na **código-fonte** editor.

\- ou -

1. Na **Gerenciador de soluções**, clique com botão direito no arquivo. rc.

2. No menu de atalho, escolha **abrir com...** , em seguida, selecione **Editor de código-fonte (texto)**.

## <a name="requirements"></a>Requisitos

Win32

## <a name="see-also"></a>Consulte também

[Arquivos de recurso](../windows/resource-files-visual-studio.md)  
[Editores de recursos](../windows/resource-editors.md)