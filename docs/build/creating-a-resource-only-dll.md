---
title: Criando uma DLL somente de recurso
ms.date: 11/04/2016
helpviewer_keywords:
- resource-only DLLs [C++], creating
- DLLs [C++], creating
ms.assetid: e6b1d4da-7275-467f-a58c-a0a8a5835199
ms.openlocfilehash: 7f0bad94cf3f126d27cc29567bd4f6c4a846bf1e
ms.sourcegitcommit: 0ab61bc3d2b6cfbd52a16c6ab2b97a8ea1864f12
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/23/2019
ms.locfileid: "62274242"
---
# <a name="creating-a-resource-only-dll"></a>Criando uma DLL somente de recurso

Uma DLL somente de recursos é uma DLL que contém nada além de recursos, como ícones, bitmaps, cadeias de caracteres e caixas de diálogo. Uso de uma DLL somente de recursos é uma boa maneira de compartilhar o mesmo conjunto de recursos entre vários programas. Também é uma boa maneira de fornecer um aplicativo com recursos localizados para vários idiomas (consulte [recursos localizados em aplicativos MFC: DLLs satélites](localized-resources-in-mfc-applications-satellite-dlls.md)).

Para criar uma DLL somente de recursos, você cria um novo projeto de DLL do Win32 (não MFC) e adicione seus recursos ao projeto.

- Selecione o projeto do Win32 na **novo projeto** caixa de diálogo caixa e especifique um tipo de projeto DLL no Assistente de projeto do Win32.

- Criar um novo script de recurso que contém os recursos (como uma cadeia de caracteres ou um menu) para a DLL e salve o arquivo. rc.

- Sobre o **Project** menu, clique em **Add Existing Item**e, em seguida, inserir o novo arquivo. rc no projeto.

- Especifique o [/NOENTRY](reference/noentry-no-entry-point.md) a opção de vinculador. /NOENTRY impede que o vinculador vincule uma referência ao `_main` a DLL; essa opção é necessária para criar uma DLL somente recurso.

- Compile a DLL.

O aplicativo que usa a DLL somente de recursos deve chamar [LoadLibrary](loadlibrary-and-afxloadlibrary.md) vincular explicitamente para a DLL. Para acessar os recursos, chame as funções genéricas `FindResource` e `LoadResource`, que funcionam em qualquer tipo de recurso, ou chamar uma das seguintes funções específicas do recurso:

- `FormatMessage`

- `LoadAccelerators`

- `LoadBitmap`

- `LoadCursor`

- `LoadIcon`

- `LoadMenu`

- `LoadString`

O aplicativo deve chamar `FreeLibrary` quando ele for concluído usando os recursos.

## <a name="see-also"></a>Consulte também

[Trabalhando com arquivos de recurso](../windows/working-with-resource-files.md)<br/>
[DLLs no Visual C++](dlls-in-visual-cpp.md)
