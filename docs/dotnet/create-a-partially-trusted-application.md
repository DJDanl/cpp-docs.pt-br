---
title: 'Como: Criar um aplicativo parcialmente confiável (C++/CLI)'
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
ms.openlocfilehash: 9df3a751f4073472b9495425599aaf43878db99a
ms.sourcegitcommit: c123cc76bb2b6c5cde6f4c425ece420ac733bf70
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/14/2020
ms.locfileid: "81364398"
---
# <a name="how-to-create-a-partially-trusted-application-by-removing-dependency-on-the-crt-library-dll"></a>Como criar um aplicativo confiável parcialmente removendo a dependência da DLL de biblioteca CRT

Este tópico discute como criar um aplicativo de tempo de execução de linguagem comum parcialmente confiável usando o Visual C++ removendo a dependência do msvcm90.dll.

Um aplicativo Visual C++ construído com **/clr** terá uma dependência do msvcm90.dll, que faz parte da Biblioteca C-Runtime. Quando você quiser que seu aplicativo seja usado em um ambiente de confiança parcial, a CLR aplicará certas regras de segurança de acesso a código em sua DLL. Portanto, será necessário remover essa dependência porque o msvcm90.dll contém código nativo e a política de segurança de acesso ao código não pode ser aplicada sobre ela.

Se o aplicativo não usar nenhuma funcionalidade da Biblioteca C-Runtime e você quiser remover a dependência desta biblioteca do seu código, você terá que usar a opção **/NODEFAULTLIB:msvcmrt.lib** linker e vincular-se com ptrustm.lib ou ptrustmd.lib. Essas bibliotecas contêm arquivos de objetos para inicialização e não inicialização de um aplicativo, classes de exceção usadas pelo código de inicialização e código de manipulação de exceção gerenciado. A vinculação em uma dessas bibliotecas removerá qualquer dependência do msvcm90.dll.

> [!NOTE]
> A ordem de montagem não inicialização pode diferir para aplicativos que usam as bibliotecas ptrust. Para aplicações normais, os conjuntos geralmente são descarregados na ordem inversa que são carregados, mas isso não é garantido. Para aplicações de confiança parcial, os conjuntos geralmente são descarregados na mesma ordem em que são carregados. Isso, também, não é garantido.

### <a name="to-create-a-partially-trusted-mixed-clr-application"></a>Para criar um aplicativo misto parcialmente confiável (/clr)

1. Para remover a dependência do linker msvcm90.dll, você deve especificar ao linker não incluir esta biblioteca usando a opção de linker **/NODEFAULTLIB:msvcmrt.lib.** Para obter informações sobre como fazer isso usando o ambiente de desenvolvimento do Visual Studio ou programáticamente, consulte [/NODEFAULTLIB (Ignorar bibliotecas)](../build/reference/nodefaultlib-ignore-libraries.md).

1. Adicione uma das bibliotecas ptrustm às dependências de entrada do linker. Use ptrustm.lib se estiver construindo seu aplicativo no modo de liberação. Para o modo de depuração, use ptrustmd.lib. Para obter informações sobre como fazer isso usando o ambiente de desenvolvimento do Visual Studio ou programáticamente, consulte [. Arquivos Lib como entrada do Linker](../build/reference/dot-lib-files-as-linker-input.md).

## <a name="see-also"></a>Confira também

[Assemblies mistos (nativos e gerenciados)](../dotnet/mixed-native-and-managed-assemblies.md)<br/>
[Inicialização de Assembléias Mistas](../dotnet/initialization-of-mixed-assemblies.md)<br/>
[Suporte de biblioteca para assemblies mistos](../dotnet/library-support-for-mixed-assemblies.md)<br/>
[/link (passar opções para o vinculador)](../build/reference/link-pass-options-to-linker.md)
