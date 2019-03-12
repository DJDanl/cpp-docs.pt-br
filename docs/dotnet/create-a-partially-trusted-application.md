---
title: 'Como: Criar um aplicativo parcialmente confiável (C + + / CLI)'
ms.custom: get-started-article
ms.date: 11/04/2016
helpviewer_keywords:
- partially trusted applications [C++]
- mixed assemblies [C++], partially trusted applications
- msvcm90[d].dll
- interoperability [C++], partially trusted applications
- interop [C++], partially trusted applications
- /clr compiler option [C++], partially trusted applications
ms.assetid: 4760cd0c-4227-4f23-a7fb-d25b51bf246e
ms.openlocfilehash: afdfb8ca11753d7def9d7da6f431082b1a90c345
ms.sourcegitcommit: dedd4c3cb28adec3793329018b9163ffddf890a4
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 03/11/2019
ms.locfileid: "57743753"
---
# <a name="how-to-create-a-partially-trusted-application-by-removing-dependency-on-the-crt-library-dll"></a>Como: Criar um aplicativo parcialmente confiável removendo a dependência da biblioteca CRT DLL

Este tópico discute como criar um aplicativo parcialmente confiável do Common Language Runtime usando o Visual C++, removendo a dependência no msvcm90.dll.

Um aplicativo do Visual C++ compilado com **/clr** terá uma dependência no msvcm90.dll, que é parte da biblioteca de tempo de execução C. Quando você quiser que seu aplicativo a ser usado em um ambiente de confiança parcial, o CLR irá impor certas regras de segurança de acesso do código em sua DLL. Portanto, será necessário remover essa dependência porque msvcm90.dll contém código nativo e não pode ser aplicada a política de segurança de acesso do código nele.

Se seu aplicativo não usar nenhuma funcionalidade da biblioteca de tempo de execução C, e você gostaria de remover a dependência nesta biblioteca no seu código, você terá que usar o **/NODEFAULTLIB:msvcmrt.lib** a opção de vinculador e vincule com ptrustm.lib ou ptrustmd.lib. Essas bibliotecas contêm arquivos de objeto para inicialização e cancelamento de um aplicativo, classes de exceção usado pelo código de inicialização e gerenciados de código de tratamento de exceção. Vinculando em uma dessas bibliotecas removerá qualquer dependência de msvcm90.dll.

> [!NOTE]
>  A ordem dos desinicialização assembly pode ser diferentes para aplicativos que usam as bibliotecas ptrust. Para aplicativos normais, assemblies normalmente são descarregados na ordem inversa em que eles são carregados, mas isso não é garantido. Para aplicativos de confiança parcial, assemblies normalmente são descarregados na mesma ordem que eles sejam carregados. Isso, além disso, não é garantido.

### <a name="to-create-a-partially-trusted-mixed-clr-application"></a>Para criar um parcialmente confiável misto (/ clr) aplicativo

1. Para remover a dependência no msvcm90.dll, você deve especificar para o vinculador para não incluir essa biblioteca usando o **/NODEFAULTLIB:msvcmrt.lib** a opção de vinculador. Para obter informações sobre como fazer isso usando o ambiente de desenvolvimento do Visual Studio ou programaticamente, consulte [/NODEFAULTLIB (ignorar bibliotecas)](../build/reference/nodefaultlib-ignore-libraries.md).

1. Adicione uma das bibliotecas ptrustm às dependências de entrada do vinculador. Use ptrustm.lib se você estiver compilando um aplicativo no modo de versão. Para o modo de depuração, use ptrustmd.lib. Para obter informações sobre como fazer isso usando o ambiente de desenvolvimento do Visual Studio ou programaticamente, consulte [. Arquivos de lib como entrada de vinculador](../build/reference/dot-lib-files-as-linker-input.md).

## <a name="see-also"></a>Consulte também

[Assemblies mistos (nativos e gerenciados)](../dotnet/mixed-native-and-managed-assemblies.md)<br/>
[Inicialização de assemblies mistos](../dotnet/initialization-of-mixed-assemblies.md)<br/>
[Suporte de biblioteca para assemblies mistos](../dotnet/library-support-for-mixed-assemblies.md)<br/>
[/link (passar opções para o vinculador)](../build/reference/link-pass-options-to-linker.md)
