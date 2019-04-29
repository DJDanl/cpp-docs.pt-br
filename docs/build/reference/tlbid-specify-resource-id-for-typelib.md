---
title: /TLBID (especificar ID do recurso para TypeLib)
ms.date: 11/04/2016
f1_keywords:
- /tlbid
- VC.Project.VCLinkerTool.TypeLibraryResourceID
helpviewer_keywords:
- tlb files, specifying resource ID
- -TLBID linker option
- .tlb files, specifying resource ID
- /TLBID linker option
- TLBID linker option
- type libraries, specifying resource ID
ms.assetid: 434b28a2-4656-4d52-ac82-8b18bf486fb2
ms.openlocfilehash: c52bfb9e4b6d0e94cecb77c766ac9e82b52f1e66
ms.sourcegitcommit: 0ab61bc3d2b6cfbd52a16c6ab2b97a8ea1864f12
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/23/2019
ms.locfileid: "62317790"
---
# <a name="tlbid-specify-resource-id-for-typelib"></a>/TLBID (especificar ID do recurso para TypeLib)

```
/TLBID:id
```

## <a name="arguments"></a>Arguments

*id*<br/>
Um valor especificado pelo usuário para uma biblioteca de tipos criada pelo vinculador. Ela substitui a ID de recurso padrão de 1.

## <a name="remarks"></a>Comentários

Ao compilar um programa que usa atributos, o vinculador criará uma biblioteca de tipos. O vinculador atribuirá uma ID de recurso de 1 para a biblioteca de tipos.

Se esta ID de recurso está em conflito com um dos seus recursos existentes, você pode especificar o outra ID com /TLBID. O intervalo de valores que você pode passar para `id` é de 1 a 65535.

### <a name="to-set-this-linker-option-in-the-visual-studio-development-environment"></a>Para definir esta opção do vinculador no ambiente de desenvolvimento do Visual Studio

1. Abra a caixa de diálogo **Páginas de Propriedades** do projeto. Para obter detalhes, consulte [propriedades de compilador e de build definida C++ no Visual Studio](../working-with-project-properties.md).

1. Clique o **vinculador** pasta.

1. Clique o **IDL incorporado** página de propriedades.

1. Modificar a **ID de recurso TypeLib** propriedade.

### <a name="to-set-this-linker-option-programmatically"></a>Para definir esta opção do vinculador por meio de programação

1. Consulte <xref:Microsoft.VisualStudio.VCProjectEngine.VCLinkerTool.TypeLibraryResourceID%2A>.

## <a name="see-also"></a>Consulte também

[Referência de vinculador MSVC](linking.md)<br/>
[Opções de vinculador MSVC](linker-options.md)
