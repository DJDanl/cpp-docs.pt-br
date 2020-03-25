---
title: Editor de informações deC++versão ()
ms.date: 02/14/2019
f1_keywords:
- vc.editors.version.F1
- vc.editors.version
helpviewer_keywords:
- Version Information editor [C++], about Version Information editor
- editors, Version Information
- resource editors [C++], Version Information editor
- version information resources [C++]
- resources [C++], editing version information
- languages, version information
- New Version Info Block
- blocks, adding
- resources [C++], adding version information
- version information, adding for languages
- blocks, deleting
- version information, deleting blocks
- resources [C++], deleting version information
- VerQueryValue
- version information, accessing from within programs
- GetFileVersionInfo
- version information
ms.assetid: 772e6f19-f765-4cec-9521-0ad3eeb99f9b
ms.openlocfilehash: b083ed27b6b1f471dbec9b96e7be7a6165f8d125
ms.sourcegitcommit: 857fa6b530224fa6c18675138043aba9aa0619fb
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 03/24/2020
ms.locfileid: "80214364"
---
# <a name="version-information-editor-c"></a>Editor de informações deC++versão ()

As informações de versão consistem em identificação da empresa e do produto, um número de versão do produto e uma notificação de copyright e marca registrada. Com o **Editor de informações de versão**, você cria e mantém esses dados, que são armazenados no recurso de informações de versão. O recurso de informações de versão não é exigido por um aplicativo, mas é um local útil para coletar informações que identificam o aplicativo. As informações de versão também são usadas pelas APIs de instalação.

> [!NOTE]
> O padrão Windows é ter apenas um recurso de versão, chamado VS_VERSION_INFO.

Um recurso de informações de versão tem um bloco superior e um ou mais blocos inferiores: um único bloco de informações fixas na parte superior e um ou mais blocos de informações de versão na parte inferior (para outros idiomas e/ou conjuntos de caracteres). O bloco Top tem caixas numéricas editáveis e listas suspensas selecionáveis. Os blocos inferiores têm apenas caixas de texto editáveis.

> [!NOTE]
> Ao usar o **Editor de informações de versão**, em muitas instâncias, você pode clicar com o botão direito do mouse para exibir um menu de atalho de comandos específicos do recurso. Por exemplo, se você selecionar enquanto aponta para uma entrada de cabeçalho de bloco, o menu de atalho mostrará as **novas informações de bloco de versão** e **excluirá** os comandos de informações de bloco de versão.

## <a name="how-to"></a>Instruções

O **Editor de informações de versão** permite que você:

### <a name="to-edit-a-string-in-a-version-information-resource"></a>Para editar uma cadeia de caracteres em um recurso de informações de versão

Selecione o item uma vez para selecioná-lo e, novamente, para começar a editá-lo. Faça alterações diretamente na tabela de **informações de versão** ou no [janela Propriedades](/visualstudio/ide/reference/properties-window). As alterações feitas serão refletidas em ambos os locais.

Ao editar a chave de `FILEFLAGS` no **Editor de informações de versão**, observe que você não pode definir as propriedades de **depuração**, **compilação particular**ou de **compilação especial** na janela **Propriedades** para arquivos. rc:

- O **Editor de informações de versão** define a propriedade de **depuração** com um `#ifdef` no script de recurso, com base no sinalizador de Build de `_DEBUG`.

- Se a chave de `Private Build` tiver um **valor** definido na tabela de **informações de versão** , a propriedade de **compilação particular** correspondente na janela **Propriedades** da chave de `FILEFLAGS` será **true**. Se o **valor** estiver vazio, a propriedade será **false**. Da mesma forma, a chave de **compilação especial** na tabela de **informações de versão** está vinculada à propriedade de **compilação especial** para a chave de `FILEFLAGS`.

Você pode classificar a sequência de informações do bloco de cadeia de caracteres selecionando a **chave** ou os títulos de coluna de **valor** . Esses cabeçalhos reorganizam automaticamente as informações na sequência selecionada.

### <a name="to-add-version-information-for-another-language-new-version-info-block"></a>Para adicionar informações de versão para outro idioma (novo bloco de informações de versão)

1. Abra um recurso de informações de versão clicando duas vezes nele no [modo de exibição de recursos](how-to-create-a-resource-script-file.md#create-resources).

1. Clique com o botão direito do mouse na tabela informações de versão e escolha **novo bloco de informações de versão**.

   Esse comando adiciona um bloco de informações adicional ao recurso de informações de versão atual e abre suas propriedades correspondentes no [janela Propriedades](/visualstudio/ide/reference/properties-window).

1. Na janela **Propriedades** , escolha o idioma e o conjunto de caracteres apropriados para o novo bloco.

### <a name="to-delete-a-version-information-block"></a>Para excluir um bloco de informações de versão

1. Abra o recurso de informações de versão clicando duas vezes em seu ícone no [modo de exibição de recursos](how-to-create-a-resource-script-file.md#create-resources).

1. Clique com o botão direito do mouse no cabeçalho de bloco que você deseja excluir e escolha **excluir bloco de informações de versão**.

   Esse comando exclui o cabeçalho selecionado e deixa o restante das informações de versão intactas. Não é possível desfazer a ação.

### <a name="to-access-version-information-from-within-your-program"></a>Para acessar informações de versão de dentro de seu programa

Se você quiser acessar as informações de versão de dentro de seu programa, use a função [GetFileVersionInfo](/windows/win32/api/winver/nf-winver-getfileversioninfow) e a função [VerQueryValue](/windows/win32/api/winver/nf-winver-verqueryvaluew) .

## <a name="requirements"></a>Requisitos

Win32

## <a name="see-also"></a>Confira também

[Editores de recursos](../windows/resource-editors.md)<br/>
[Menus e outros recursos](/windows/win32/menurc/resources)<br/>
[Informações de versão (Windows)](/windows/win32/menurc/version-information)
