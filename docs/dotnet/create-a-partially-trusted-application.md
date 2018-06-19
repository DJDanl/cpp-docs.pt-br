---
title: 'Como: criar um aplicativo parcialmente confiável (C + + CLI) | Microsoft Docs'
ms.custom: get-started-article
ms.date: 11/04/2016
ms.technology:
- cpp-cli
ms.topic: conceptual
dev_langs:
- C++
helpviewer_keywords:
- partially trusted applications [C++]
- mixed assemblies [C++], partially trusted applications
- msvcm90[d].dll
- interoperability [C++], partially trusted applications
- interop [C++], partially trusted applications
- /clr compiler option [C++], partially trusted applications
ms.assetid: 4760cd0c-4227-4f23-a7fb-d25b51bf246e
author: mikeblome
ms.author: mblome
ms.workload:
- cplusplus
- dotnet
ms.openlocfilehash: a4a0a4b8b1045a9107158c6e67ecdfa7939b6a08
ms.sourcegitcommit: 76b7653ae443a2b8eb1186b789f8503609d6453e
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 05/04/2018
ms.locfileid: "33108992"
---
# <a name="how-to-create-a-partially-trusted-application-by-removing-dependency-on-the-crt-library-dll"></a>Como criar um aplicativo confiável parcialmente removendo a dependência da DLL de biblioteca CRT
Este tópico discute como criar um aplicativo de Common Language Runtime parcialmente confiável usando o Visual C++, removendo a dependência no msvcm90.dll.  
  
 Um aplicativo do Visual C++ compilado com **/clr** terá uma dependência no msvcm90.dll, que é parte da biblioteca de tempo de execução C. Quando você deseja que seu aplicativo a ser usado em um ambiente de confiança parcial, o CLR irá impor certas regras de segurança de acesso do código em sua DLL. Portanto, será necessário remover essa dependência porque msvcm90.dll contém código nativo e política de segurança de acesso do código não pode ser aplicada a ele.  
  
 Se seu aplicativo não usar nenhuma funcionalidade da biblioteca de tempo de execução do C e você gostaria de remover a dependência nesta biblioteca no seu código, você precisará usar o **/NODEFAULTLIB:msvcmrt.lib** opção de vinculador e link ptrustm.lib ou ptrustmd.lib. Essas bibliotecas contêm arquivos de objeto para inicialização e cancelamento de inicialização de um aplicativo, classes de exceção usado pelo código de inicialização e gerenciados código de tratamento de exceção. Vinculação de uma dessas bibliotecas removerá qualquer dependência em msvcm90.dll.  
  
> [!NOTE]
>  A ordem de cancelamento de inicialização de assembly pode ser diferentes para aplicativos que usam as bibliotecas de ptrust. Para aplicativos normais, assemblies geralmente são descarregados na ordem inversa em que eles são carregados, mas isso não é garantido. Para aplicativos de confiança parcial, assemblies geralmente são descarregados na mesma ordem que eles são carregados. Isso, além disso, não é garantido.  
  
### <a name="to-create-a-partially-trusted-mixed-clr-application"></a>Para criar um parcialmente confiável misto (/ clr) aplicativo  
  
1.  Para remover a dependência msvcm90.dll, você deve especificar o vinculador para não incluir essa biblioteca usando o **/NODEFAULTLIB:msvcmrt.lib** opção de vinculador. Para obter informações sobre como fazer isso usando o ambiente de desenvolvimento do Visual Studio ou programaticamente, consulte [/NODEFAULTLIB (ignorar bibliotecas)](../build/reference/nodefaultlib-ignore-libraries.md).  
  
2.  Adicione uma das bibliotecas ptrustm para as dependências de entrada de vinculador. Use ptrustm.lib se você estiver criando seu aplicativo no modo de liberação. Para o modo de depuração, use ptrustmd.lib. Para obter informações sobre como fazer isso usando o ambiente de desenvolvimento do Visual Studio ou programaticamente, consulte [. Lib arquivos como entrada de vinculador](../build/reference/dot-lib-files-as-linker-input.md).  
  
## <a name="see-also"></a>Consulte também  
 [Assemblies mistos (nativos e gerenciados)](../dotnet/mixed-native-and-managed-assemblies.md)   
 [Inicialização de Assemblies mistos](../dotnet/initialization-of-mixed-assemblies.md)   
 [Suporte de biblioteca para Assemblies mistos](../dotnet/library-support-for-mixed-assemblies.md)   
 [/link (passar opções para o vinculador)](../build/reference/link-pass-options-to-linker.md)   
