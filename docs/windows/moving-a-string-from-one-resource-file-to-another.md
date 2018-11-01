---
title: Movendo uma cadeia de caracteres de um arquivo de recurso para outro (C++)
ms.date: 11/04/2016
helpviewer_keywords:
- strings [C++], moving between files
- resource script files [C++], moving strings
- string editing, moving strings between resources
- String editor [C++], moving strings between files
ms.assetid: 94f8ee81-9b4c-4788-ba95-68c58db38029
ms.openlocfilehash: e89a0d44dc824c72710f8a047a18771ba8da492b
ms.sourcegitcommit: 6052185696adca270bc9bdbec45a626dd89cdcdd
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 10/31/2018
ms.locfileid: "50649807"
---
# <a name="moving-a-string-from-one-resource-file-to-another-c"></a>Movendo uma cadeia de caracteres de um arquivo de recurso para outro (C++)

### <a name="to-move-a-string-from-one-resource-script-file-to-another"></a>Para mover uma cadeia de caracteres do arquivo de script de um recurso para outro

1. Abra as tabelas de cadeia de caracteres em ambos os arquivos. rc. (Para obter mais informações, consulte [exibir recursos em um recurso Script arquivo externa de um projeto](../windows/how-to-open-a-resource-script-file-outside-of-a-project-standalone.md).)

   > [!NOTE]
   > Se seu projeto já não contiver um arquivo. RC, consulte [criando um novo arquivo de Script de recurso](../windows/how-to-create-a-resource-script-file.md).

2. Com a cadeia de caracteres que você deseja mover e escolha o botão direito **Recortar** no menu de atalho.

3. Coloque o cursor no destino **Editor de cadeia de caracteres** janela.

4. No arquivo. RC para o qual você deseja mover a cadeia de caracteres, com o botão direito e escolha **colar** no menu de atalho.

   > [!NOTE]
   > Se o **ID** ou **valor** dos conflitos com um cadeia de caracteres movidos **ID** ou **valor** no arquivo de destino, ambos os **Identificação** ou o **valor** das alterações de cadeia de caracteres movidos. Se uma cadeia de caracteres existe com o mesmo **identificação**, o **ID** das alterações de cadeia de caracteres movidos. Se uma cadeia de caracteres existe com o mesmo **valor**, o **valor** das alterações de cadeia de caracteres movidos.

Para obter informações sobre como adicionar recursos a projetos gerenciados (aquelas que visam o common language runtime), consulte [recursos em aplicativos de área de trabalho](/dotnet/framework/resources/index) na *guia do desenvolvedor do .NET Framework*. Para obter informações sobre como adicionar manualmente os arquivos de recursos a projetos gerenciados, acessar recursos, exibir recursos estáticos e atribuir cadeias de caracteres de recursos a propriedades, consulte [instruções passo a passo: Localizando Windows Forms](/previous-versions/visualstudio/visual-studio-2010/y99d1cd3).

## <a name="requirements"></a>Requisitos

Win32

## <a name="see-also"></a>Consulte também

[Editor de cadeias de caracteres](../windows/string-editor.md)<br/>
[Arquivos de recurso](../windows/resource-files-visual-studio.md)<br/>
[Personalizando layouts de janela](/visualstudio/ide/customizing-window-layouts-in-visual-studio)