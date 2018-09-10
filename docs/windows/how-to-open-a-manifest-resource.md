---
title: 'Como: abrir um recurso de manifesto (C++) | Microsoft Docs'
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-windows
ms.topic: conceptual
dev_langs:
- C++
helpviewer_keywords:
- manifest resources [C++]
- resources [C++], opening
ms.assetid: bd6f9c47-2a1e-417d-9d2a-c1ad7d3b9635
author: mikeblome
ms.author: mblome
ms.workload:
- cplusplus
- uwp
ms.openlocfilehash: 7bb55c18bf577e8ef7bbf1f9504af1df0e1ebe7f
ms.sourcegitcommit: f0c90000125a9497bf61e41624de189a043703c0
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 09/10/2018
ms.locfileid: "44315516"
---
# <a name="how-to-open-a-manifest-resource"></a>Como abrir um recurso de manifesto

Se você abrir um recurso de manifesto da [exibição de recurso](../windows/resource-view-window.md), o recurso será aberto no formato binário. Para exibir o conteúdo de um recurso de manifesto em um formato mais visível, você deve abrir o recurso a partir **Gerenciador de soluções**.

### <a name="to-open-a-manifest-resource-in-the-text-editor"></a>Para abrir um recurso de manifesto no Editor de texto

1. Com o projeto aberto no **Gerenciador de soluções**, expanda o **arquivos de recurso** pasta.

2. Clique duas vezes o arquivo. manifest.

   O recurso de manifesto é aberto na **Editor de texto**.

### <a name="to-open-a-manifest-resource-in-another-editor"></a>Para abrir um recurso de manifesto em outro editor

1. Na **Gerenciador de soluções**, o arquivo. manifest com o botão direito e escolha **abrir com...**  no menu de atalho.

2. No **abrir com** caixa de diálogo, especifique o editor que você gostaria de usar e clique em **abrir**.

Para obter informações sobre como adicionar recursos a projetos gerenciados, consulte [recursos em aplicativos de área de trabalho](/dotnet/framework/resources/index) na *guia do desenvolvedor do .NET Framework*.

## <a name="requirements"></a>Requisitos

Win32

## <a name="see-also"></a>Consulte também

[Recursos de manifesto](../windows/manifest-resources.md)  
[Controles](../mfc/controls-mfc.md)  
[Trabalhando com arquivos de recurso](../windows/working-with-resource-files.md)