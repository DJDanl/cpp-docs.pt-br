---
title: Editando dados binários (C++) | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-windows
ms.topic: conceptual
f1_keywords:
- vc.editors.binary
dev_langs:
- C++
helpviewer_keywords:
- binary data, editing
- binary data
ms.assetid: 0fd429de-baf1-4871-b5e4-42bf868a3261
author: mikeblome
ms.author: mblome
ms.workload:
- cplusplus
- uwp
ms.openlocfilehash: 050f52dface260da77f7290f47a9cbb204caaafe
ms.sourcegitcommit: f0c90000125a9497bf61e41624de189a043703c0
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 09/10/2018
ms.locfileid: "44315452"
---
# <a name="editing-binary-data"></a>Editando dados binários

### <a name="to-edit-a-resource-in-the-binary-editor"></a>Para editar um recurso no editor binário

1. Selecione o byte que você deseja editar.

   O **guia** chave move o foco entre hexadecimal e seções ASCII a **binário** editor. Você pode usar o **Page Up** e **Page Down** chaves para mover por meio da tela de um recurso por vez.

2. Digite o novo valor.

   O valor é alterado imediatamente em hexadecimal e seções de ASCII e o foco muda para o próximo valor na linha.

   > [!NOTE]
   > O **binário** editor aceita alterações automaticamente quando você fecha o editor.

Para obter informações sobre como adicionar recursos a projetos gerenciados, consulte [recursos em aplicativos de área de trabalho](/dotnet/framework/resources/index) na *guia do desenvolvedor do .NET Framework*. Para obter informações sobre como adicionar manualmente os arquivos de recursos a projetos gerenciados, acessar recursos, exibir recursos estáticos e atribuir cadeias de caracteres de recurso a propriedades, consulte [criando arquivos de recursos para aplicativos de área de trabalho](/dotnet/framework/resources/creating-resource-files-for-desktop-apps). Para obter informações sobre globalização e localização de recursos em aplicativos gerenciados, consulte [Globalizing e Localizando aplicativos do .NET Framework](/dotnet/standard/globalization-localization/index).

## <a name="requirements"></a>Requisitos

Nenhum

## <a name="see-also"></a>Consulte também

[Editor binário](binary-editor.md)