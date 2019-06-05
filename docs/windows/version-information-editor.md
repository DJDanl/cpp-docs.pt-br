---
title: Editor de informações de versão (C++)
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
ms.openlocfilehash: a17539d0a9fb94c440d65275e9d032182088ae6e
ms.sourcegitcommit: ecf274bcfe3a977c48745aaa243e5e731f1fdc5f
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 06/04/2019
ms.locfileid: "66504482"
---
# <a name="version-information-editor-c"></a>Editor de informações de versão (C++)

Informações de versão consistem da empresa e identificação de produto, um número de versão do produto e a notificação de direitos autorais e marcas. Com o **Editor de informações de versão**, criar e manter esses dados, que são armazenados no recurso de informações da versão. O recurso de informações de versão não é necessário por um aplicativo, mas é um local útil para coletar informações que identificam o aplicativo. Informações de versão também são usadas por APIs de configuração.

> [!NOTE]
> O padrão do Windows é ter apenas uma versão recurso, chamado VS_VERSION_INFO.

Um recurso de informações de versão tem um bloco superior e um ou mais blocos inferiores: um único bloco de informações fixa na parte superior e um ou mais blocos de informações de versão na parte inferior (para outros idiomas e/ou conjuntos de caracteres). O bloco superior tem caixas numéricas editáveis e selecionável nas listas suspensas. Os blocos menores têm apenas as caixas de texto editável.

> [!NOTE]
> Ao usar o **Editor de informações de versão**, em muitos casos você pode clique com botão direito para exibir um menu de atalho de comandos específicos ao recurso. Por exemplo, se você selecionar ao mesmo tempo, que aponta para uma entrada de cabeçalho do bloco, o menu de atalho mostra a **novas informações de versão de bloco** e **excluir informações de versão de bloco** comandos.

## <a name="how-to"></a>Como

O **Editor de informações de versão** permite que você:

### <a name="to-edit-a-string-in-a-version-information-resource"></a>Para editar uma cadeia de caracteres em um recurso de informações de versão

Selecione o item de uma vez para escolha, em seguida, novamente para começar a editá-lo. Fazer alterações diretamente na **informações de versão** tabela ou o [janela propriedades](/visualstudio/ide/reference/properties-window). As alterações feitas serão refletidas em ambos os locais.

Ao editar o `FILEFLAGS` principais na **Editor de informações de versão**, observe que não é possível definir a **depurar**, **compilação particular**, ou **compilação especial**  propriedades de **propriedades** janela para arquivos. RC:

   - O **Editor de informações de versão** define o **depurar** propriedade com um `#ifdef` script de recurso, com base no `_DEBUG` sinalizador de compilação.

  - Se o `Private Build` chave tem um **valor** definida **informações de versão** tabela correspondente **compilação particular** propriedade no **propriedades**  janela para o `FILEFLAGS` chave será **verdadeiro**. Se **valor** estiver vazio, a propriedade será **falso**. Da mesma forma, o **compilação especial** chave na **informações de versão** tabela está vinculada ao **Build especial** propriedade para o `FILEFLAGS` chave.

Você pode classificar a sequência de informações do bloco de cadeia de caracteres, selecionando o **chave** ou o **valor** títulos de coluna. Esses títulos de reorganizar automaticamente as informações na sequência selecionada.

### <a name="to-add-version-information-for-another-language-new-version-info-block"></a>Para adicionar informações de versão para outro idioma (novo bloco de informações de versão)

1. Abrir um recurso de informações de versão clicando duas vezes no [exibição de recurso](how-to-create-a-resource-script-file.md#create-resources).

1. Clique dentro da tabela de informações de versão e escolha **novo bloco de informações de versão**.

   Este comando adiciona um bloco de informações adicionais para o recurso de informações de versão atual e abre suas propriedades correspondentes na [janela de propriedades](/visualstudio/ide/reference/properties-window).

1. No **propriedades** janela, escolha o idioma apropriado e do conjunto para o novo bloco de caracteres.

### <a name="to-delete-a-version-information-block"></a>Para excluir um bloco de informações de versão

1. Abra o recurso de informações de versão clicando duas vezes em seu ícone no [exibição de recurso](how-to-create-a-resource-script-file.md#create-resources).

1. Clique com botão direito do cabeçalho de bloco que deseja excluir e escolha **Excluir Bloco de informações de versão**.

   Esse comando exclui o cabeçalho selecionado e deixa o restante das informações de versão intacta. Você não pode desfazer a ação.

### <a name="to-access-version-information-from-within-your-program"></a>Para acessar informações de versão do seu programa

Se você quiser acessar as informações de versão do seu programa, use o [GetFileVersionInfo](/windows/desktop/api/winver/nf-winver-getfileversioninfoa) função e o [VerQueryValue](/windows/desktop/api/winver/nf-winver-verqueryvaluea) função.

## <a name="requirements"></a>Requisitos

Win32

## <a name="see-also"></a>Consulte também

[Editores de recursos](../windows/resource-editors.md)<br/>
[Menus e outros recursos](/windows/desktop/menurc/resources)<br/>
[Informações de versão (Windows)](/windows/desktop/menurc/version-information)
