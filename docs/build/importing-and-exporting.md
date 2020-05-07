---
title: Importando e exportando
ms.date: 05/06/2019
helpviewer_keywords:
- DLLs [C++], importing
- exporting DLLs [C++]
- importing DLLs [C++]
- DLLs [C++], exporting from
- __declspec(dllimport) keyword [C++]
ms.assetid: 7c44c2aa-2117-4cec-9615-a65bfd3f8f7b
ms.openlocfilehash: 03931f7f128ab0666890bb8e76677db67dda8fc7
ms.sourcegitcommit: da32511dd5baebe27451c0458a95f345144bd439
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 05/07/2019
ms.locfileid: "65220635"
---
# <a name="importing-and-exporting"></a>Importando e exportando

Você pode importar símbolos públicos em um aplicativo ou exportar funções de uma DLL usando dois métodos:

- Usar um arquivo de definição de módulo (. def) ao compilar a DLL

- Use as palavras-chave **__declspec (dllimport)** ou **__declspec (dllexport)** em uma definição de função no aplicativo principal

## <a name="using-a-def-file"></a>Usando um arquivo. def

Um arquivo de definição de módulo (. def) é um arquivo de texto que contém uma ou mais instruções de módulo que descrevem vários atributos de uma DLL. Se você não usar **__declspec (dllimport)** ou **__declspec (dllexport)** para exportar as funções de uma dll, a dll exigirá um arquivo. def.

Você pode usar arquivos. def para [importar para um aplicativo](importing-using-def-files.md) ou para [Exportar de uma DLL](exporting-from-a-dll-using-def-files.md).

## <a name="using-__declspec"></a>Usando __declspec

Você não precisa usar o **__declspec (dllimport)** para que seu código seja compilado corretamente, mas isso permite que o compilador gere um código melhor. O compilador é capaz de gerar um código melhor, pois ele pode determinar se uma função existe em uma DLL ou não, o que permite que o compilador produza um código que ignora um nível de indireção que normalmente estaria presente em uma chamada de função que cruzou um limite de DLL. No entanto, você deve usar **__declspec (dllimport)** para importar variáveis usadas em uma dll.

Com a seção de exportações de arquivo. def apropriada, **__declspec (dllexport)** não é necessário. **__declspec (dllexport)** foi adicionado para fornecer uma maneira fácil de exportar funções de um arquivo. exe ou. dll sem usar um arquivo. def.

O formato executável portátil do Win32 foi projetado para minimizar o número de páginas que devem ser tocadas para corrigir importações. Para fazer isso, ele coloca todos os endereços de importação de qualquer programa em um único lugar chamado tabela de endereços de importação. Isso permite que o carregador modifique apenas uma ou duas páginas ao acessar essas importações.

## <a name="what-do-you-want-to-do"></a>O que você deseja fazer?

- [Importar para um aplicativo](importing-into-an-application-using-declspec-dllimport.md)

- [Exportar de uma DLL](exporting-from-a-dll.md)

## <a name="see-also"></a>Confira também

[Criar DLLs C /C++ no Visual Studio](dlls-in-visual-cpp.md)
