---
title: Assemblies de nome forte (assinatura de assembly) (C++/CLI)
ms.date: 11/04/2016
helpviewer_keywords:
- assemblies [C++]
- signing assemblies
- .NET Framework [C++], assembly signing
- assemblies [C++], signing
- linker [C++], assembly signing
- strong-named assemblies [C++]
ms.assetid: c337cd3f-e5dd-4c6f-a1ad-437e85dba1cc
ms.openlocfilehash: c23c3b70a2152fbceb771e085b73d7daf7aa3c2a
ms.sourcegitcommit: 6052185696adca270bc9bdbec45a626dd89cdcdd
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 10/31/2018
ms.locfileid: "50527550"
---
# <a name="strong-name-assemblies-assembly-signing-ccli"></a>Assemblies de nome forte (assinatura de assembly) (C++/CLI)

Este tópico discute como você pode assinar o assembly, também conhecido como dando seu assembly um nome forte.

## <a name="remarks"></a>Comentários

Ao usar o Visual C++, use as opções do vinculador para assinar seu assembly para evitar problemas relacionados aos atributos CLR para a assinatura do assembly:

- <xref:System.Reflection.AssemblyDelaySignAttribute>

- <xref:System.Reflection.AssemblyKeyFileAttribute>

- <xref:System.Reflection.AssemblyKeyNameAttribute>

Motivos para não usar os atributos incluem o fato de que o nome da chave é visível nos metadados do assembly, que podem ser um risco à segurança se o nome do arquivo contém informações confidenciais. Além disso, o processo de compilação usado pelo ambiente de desenvolvimento do Visual C++ invalida a chave com a qual o assembly é assinado se você usa atributos CLR para dar um nome forte de um assembly e, em seguida, execute uma ferramenta de pós-processamento como mt.exe no assembly.

Se você compilar na linha de comando, use as opções do vinculador para assinar seu assembly e, em seguida, execute uma ferramenta de pós-processamento (como mt.exe), você precisará assinar novamente o assembly com sn.exe. Como alternativa, é possível criar e atrasar a assinatura de assembly e depois de executar as ferramentas de pós-processamento, concluir a assinatura.

Se você usar os atributos de assinatura ao compilar no ambiente de desenvolvimento, você pode entrar com êxito o assembly explicitamente chamando sn.exe ([Sn.exe (ferramenta de nome forte)](/dotnet/framework/tools/sn-exe-strong-name-tool)) em um evento de pós-compilação. Para obter mais informações, confira [Especificando eventos de build](../ide/specifying-build-events.md). Tempos de compilação podem ser menor, se você usar um evento de pós-compilação, em comparação ao uso de um opções do vinculador e de atributos.

As seguintes opções do vinculador dão suporte a assinatura do assembly:

- [/DELAYSIGN (assinar parcialmente um assembly)](../build/reference/delaysign-partially-sign-an-assembly.md)

- [/KEYFILE (especificar chave ou par de chaves para assinar um assembly)](../build/reference/keyfile-specify-key-or-key-pair-to-sign-an-assembly.md)

- [/KEYCONTAINER (especificar um contêiner de chave para assinar um assembly)](../build/reference/keycontainer-specify-a-key-container-to-sign-an-assembly.md)

Para obter mais informações sobre conjuntos de alta segurança, consulte [criando e usando Assemblies nomes fortes](/dotnet/framework/app-domains/create-and-use-strong-named-assemblies).

## <a name="see-also"></a>Consulte também

[Programação do .NET com C++/CLI (Visual C++)](../dotnet/dotnet-programming-with-cpp-cli-visual-cpp.md)