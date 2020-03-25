---
title: Como instanciar componentes WRL diretamente
ms.date: 11/04/2016
ms.topic: reference
ms.assetid: 1a9fa011-0cee-4abf-bf83-49adf53ff906
ms.openlocfilehash: f291e982d7f77c63821e5943a5867662ccd1b4fa
ms.sourcegitcommit: 857fa6b530224fa6c18675138043aba9aa0619fb
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 03/24/2020
ms.locfileid: "80213896"
---
# <a name="how-to-instantiate-wrl-components-directly"></a>Como instanciar componentes WRL diretamente

Saiba como usar a WRL ( C++ biblioteca de modelos de Windows Runtime)[Microsoft:: WRL:: Make](make-function.md) e [Microsoft:: WRL::D etalhes:: MakeAndInitialize](makeandinitialize-function.md) Functions para instanciar um componente do módulo que o define.

Ao instanciar componentes diretamente, você pode reduzir a sobrecarga quando não precisar de fábricas de classe ou outros mecanismos. Você pode criar uma instância de um componente diretamente em ambos os Plataforma Universal do Windows aplicativos e em aplicativos de área de trabalho.

Para saber como usar Windows Runtime C++ biblioteca de modelos para criar um componente com clássico e instanciá-lo de um aplicativo de área de trabalho externa, consulte [como criar um componente com clássico](how-to-create-a-classic-com-component-using-wrl.md).

Este documento mostra dois exemplos. O primeiro exemplo usa a função `Make` para criar uma instância de um componente. O segundo exemplo usa a função `MakeAndInitialize` para criar uma instância de um componente que pode falhar durante a construção. (Como o COM normalmente usa valores HRESULT, em vez de exceções, para indicar erros, um tipo COM normalmente não é gerado a partir de seu construtor. `MakeAndInitialize` permite que um componente Valide seus argumentos de construção por meio do método `RuntimeClassInitialize`.) Ambos os exemplos definem uma interface básica do agente e implementam essa interface definindo uma classe que grava mensagens no console.

> [!IMPORTANT]
> Você não pode usar o operador de `new` para C++ instanciar Windows Runtime componentes da biblioteca de modelos. Portanto, recomendamos que você sempre use `Make` ou `MakeAndInitialize` para instanciar um componente diretamente.

### <a name="to-create-and-instantiate-a-basic-logger-component"></a>Para criar e instanciar um componente básico do agente de log

1. No Visual Studio, crie um projeto de **aplicativo de console do Win32** . Nomeie o projeto, por exemplo, *WRLLogger*.

2. Adicione um arquivo **MIDL (. idl)** ao projeto, nomeie o arquivo `ILogger.idl`e, em seguida, adicione este código:

   [!code-cpp[wrl-logger-make#1](../codesnippet/CPP/how-to-instantiate-wrl-components-directly_1.idl)]

3. Use o código a seguir para substituir o conteúdo de `WRLLogger.cpp`.

   [!code-cpp[wrl-logger-make#2](../codesnippet/CPP/how-to-instantiate-wrl-components-directly_2.cpp)]

### <a name="to-handle-construction-failure-for-the-basic-logger-component"></a>Para lidar com a falha de construção do componente agente básico

1. Use o código a seguir para substituir a definição da classe `CConsoleWriter`. Esta versão contém uma variável de membro de cadeia de caracteres privada e substitui o método `RuntimeClass::RuntimeClassInitialize`. `RuntimeClassInitialize` falhará se a chamada para `SHStrDup` falhar.

   [!code-cpp[wrl-logger-makeandinitialize#1](../codesnippet/CPP/how-to-instantiate-wrl-components-directly_3.cpp)]

2. Use o código a seguir para substituir a definição de `wmain`. Essa versão usa `MakeAndInitialize` para instanciar o objeto `CConsoleWriter` e verificar o resultado HRESULT.

   [!code-cpp[wrl-logger-makeandinitialize#2](../codesnippet/CPP/how-to-instantiate-wrl-components-directly_4.cpp)]

## <a name="see-also"></a>Confira também

[WRL (Biblioteca de Modelos C++ do Tempo de Execução do Windows)](windows-runtime-cpp-template-library-wrl.md)<br/>
[Microsoft:: WRL:: Make](make-function.md)<br/>
[Microsoft:: WRL::D etalhes:: MakeAndInitialize](makeandinitialize-function.md)
