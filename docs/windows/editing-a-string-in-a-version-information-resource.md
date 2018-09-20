---
title: Editando uma cadeia de caracteres em um recurso de informações de versão (C++) | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-windows
ms.topic: conceptual
f1_keywords:
- vc.editors.version
dev_langs:
- C++
helpviewer_keywords:
- version information resources [C++]
- resources [C++], editing version information
ms.assetid: d3a7d4e4-7d31-47c2-902c-f50b8404ba4f
author: mikeblome
ms.author: mblome
ms.workload:
- cplusplus
- uwp
ms.openlocfilehash: 87fac131c053afa3c3b6d6da549d7a002fa95b64
ms.sourcegitcommit: 799f9b976623a375203ad8b2ad5147bd6a2212f0
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 09/19/2018
ms.locfileid: "46445016"
---
# <a name="editing-a-string-in-a-version-information-resource-c"></a>Editando uma cadeia de caracteres em um recurso de informações de versão (C++)

### <a name="to-edit-a-string-in-a-version-information-resource"></a>Para editar uma cadeia de caracteres em um recurso de informações de versão

1. Clique no item uma vez para selecioná-la, em seguida, novamente para começar a editá-lo. Faça as alterações diretamente na **informações de versão** tabela ou nos [janela propriedades](/visualstudio/ide/reference/properties-window). As alterações feitas serão refletidas em ambos os locais.

   > [!NOTE] 
   > Ao editar o `FILEFLAGS` principais na **informações de versão** editor, você observará que não é possível definir a **depurar**, **compilação particular**, ou **especiais Crie** propriedades (na **propriedades** janela) para arquivos. RC:

   - O **informações de versão** define o **depurar** propriedade com um `#ifdef` script de recurso, com base no `_DEBUG` sinalizador de compilação.

   - Se o `Private Build` chave tem um **valor** definida **informações de versão** tabela correspondente **compilação particular** propriedade (no **propriedades**  janela) para o `FILEFLAGS` chave será **verdadeiro**. Se o **valor** estiver vazio, a propriedade será **falso**. Da mesma forma, o **compilação especial** chave (na **informações de versão** tabela) está vinculado ao **Build especial** propriedade para o `FILEFLAGS` chave.

Você pode classificar a sequência de informações do bloco de cadeia de caracteres clicando-se a chave ou os cabeçalhos de coluna de valor. Esses títulos de reorganizar automaticamente as informações na sequência selecionada.

Para obter informações sobre como adicionar recursos a projetos gerenciados, consulte [recursos em aplicativos de área de trabalho](/dotnet/framework/resources/index) na *guia do desenvolvedor do .NET Framework*. Para obter informações sobre como adicionar manualmente os arquivos de recursos a projetos gerenciados, acessar recursos, exibir recursos estáticos e atribuir cadeias de caracteres de recurso a propriedades, consulte [criando arquivos de recursos para aplicativos de área de trabalho](/dotnet/framework/resources/creating-resource-files-for-desktop-apps). Para obter informações sobre globalização e localização de recursos em aplicativos gerenciados, consulte [Globalizing e Localizando aplicativos do .NET Framework](/dotnet/standard/globalization-localization/index).

## <a name="requirements"></a>Requisitos

Win32

## <a name="see-also"></a>Consulte também

[Editor de informações de versão](../windows/version-information-editor.md)<br/>
[Informações de versão (Windows)](https://msdn.microsoft.com/library/windows/desktop/ms646981.aspx)