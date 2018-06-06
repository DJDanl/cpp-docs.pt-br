---
title: 'Como: criar projetos C++ verificáveis (C++ /CLI CLI) | Microsoft Docs'
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-cli
ms.topic: conceptual
dev_langs:
- C++
helpviewer_keywords:
- verifiable assemblies [C++], creating
- conversions, C++ projects
- Visual C++ projects
ms.assetid: 4ef2cc1a-e3e5-4d67-8d8d-9c614f8ec5d3
author: mikeblome
ms.author: mblome
ms.workload:
- cplusplus
- dotnet
ms.openlocfilehash: 36e7ee85d97639df6298a346ae83bb090e81bf87
ms.sourcegitcommit: a4454b91d556a3dc43d8755cdcdeabcc9285a20e
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 06/04/2018
ms.locfileid: "34704757"
---
# <a name="how-to-create-verifiable-c-projects-ccli"></a>Como: criar projetos do C++ verificáveis (C++ /CLI CLI)

Assistentes de aplicativo do Visual C++ não criar projetos verificáveis.

> [!IMPORTANT]
> Preterido do Visual Studio 2015 e 2017 do Visual Studio não dá suporte a **/clr: pure** e **/CLR: safe** criação de projetos verificáveis. Se você precisar de código verificável, é recomendável que converter seu código c#.

No entanto, se você estiver usando uma versão mais antiga do conjunto de ferramentas de compilador do Visual C++ que dá suporte a **/clr: pure** e **/CLR: safe**, projetos podem ser convertidos para que seja verificável. Este tópico descreve como definir propriedades do projeto e modificar arquivos de origem do projeto para transformar seus projetos do Visual C++ para produzir aplicativos verificáveis.

## <a name="compiler-and-linker-settings"></a>Configurações de compilador e vinculador

 Por padrão, os projetos do .NET usam o sinalizador de compilador /clr e configurar o vinculador para hardware de destino x86. Código verificável, você deve usar o sinalizador /CLR: safe, e você deve instruir o vinculador para gerar MSIL em vez de instruções de máquina nativo.

### <a name="to-change-the-compiler-and-linker-settings"></a>Para alterar as configurações de compilador e vinculador

1. Exiba o página de propriedades do projeto. Para obter mais informações, consulte [trabalhar com propriedades do projeto](../ide/working-with-project-properties.md).

1. No **geral** página sob o **propriedades de configuração** do conjunto de nós, o **suporte a Common Language Runtime** propriedade para **seguro MSIL Common Language Suporte de tempo de execução (/: Safe)**.

1. No **avançado** página sob o **vinculador** do conjunto de nós, o **tipo de imagem CLR** propriedade para **forçar imagem IL segura (/ /CLRIMAGETYPE: Safe)**.

## <a name="removing-native-data-types"></a>Removendo tipos de dados nativos

Como tipos de dados nativos não verificável mesmo se, na verdade, não são usados, você deve remover todos os arquivos de cabeçalho que contém os tipos nativos.

> [!NOTE]
> O procedimento a seguir se aplicam a projetos de aplicativos de formulários do Windows (.NET) e o aplicativo de Console (.NET).

### <a name="to-remove-references-to-native-data-types"></a>Para remover as referências aos tipos de dados nativos

1. Comentar tudo no arquivo Stdafx. h.

## <a name="configuring-an-entry-point"></a>Configurando um ponto de entrada

Como aplicativos verificáveis não podem usar as bibliotecas de tempo de execução do C (CRT), eles não podem depender CRT para chamar a função principal como o ponto de entrada padrão. Isso significa que você deve fornecer explicitamente o nome da função a ser chamada inicialmente para o vinculador. (Nesse caso, Main () é usado em vez Main () ou _tmain() para indicar um ponto de entrada não CRT, mas porque o ponto de entrada deve ser especificado explicitamente, esse nome é arbitrário.)

> [!NOTE]
> Os procedimentos a seguir se aplicam a projetos de aplicativo de Console (.NET).

#### <a name="to-configure-an-entry-point"></a>Para configurar um ponto de entrada

1. Altere _tmain() em Main () no arquivo. cpp principal do projeto.

1. Exiba o página de propriedades do projeto. Para obter mais informações, consulte [trabalhar com propriedades do projeto](../ide/working-with-project-properties.md).

1. No **avançado** página sob o **vinculador** nó, insira `Main` como o **ponto de entrada** valor da propriedade.

## <a name="see-also"></a>Consulte também

- [Código puro e verificável (C++/CLI)](../dotnet/pure-and-verifiable-code-cpp-cli.md)
