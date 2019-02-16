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
ms.openlocfilehash: 8420feb6ddde116a24bee5333f4ef8f83ff4e0d4
ms.sourcegitcommit: 470de1337035dd33682d935b4b6c6d8b1bdb0bbb
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 02/15/2019
ms.locfileid: "56320465"
---
# <a name="version-information-editor-c"></a>Editor de informações de versão (C++)

Informações de versão consistem da empresa e identificação de produto, um número de versão do produto e a notificação de direitos autorais e marcas. Com o **informações de versão** editor, criar e manter esses dados, que são armazenados no recurso de informações da versão. O recurso de informações de versão não é necessário por um aplicativo, mas é um local útil para coletar informações que identificam o aplicativo. Informações de versão também são usadas por APIs de configuração.

Um recurso de informações de versão tem um bloco superior e um ou mais blocos inferiores: um único bloco de informações fixa na parte superior e um ou mais blocos de informações de versão na parte inferior (para outros idiomas e/ou conjuntos de caracteres). O bloco superior tem caixas numéricas editáveis e selecionável nas listas suspensas. Os blocos menores têm apenas as caixas de texto editável.

> [!NOTE]
> O padrão do Windows é ter apenas uma versão recurso, chamado VS_VERSION_INFO.

## <a name="how-to"></a>Como fazer

O **informações de versão** editor permite que você:

### <a name="to-edit-a-string-in-a-version-information-resource"></a>Para editar uma cadeia de caracteres em um recurso de informações de versão

Selecione o item de uma vez para escolha, em seguida, novamente para começar a editá-lo. Faça as alterações diretamente na **informações de versão** tabela ou nos [janela propriedades](/visualstudio/ide/reference/properties-window). As alterações feitas serão refletidas em ambos os locais.

Ao editar o `FILEFLAGS` principais na **informações de versão** editor, você observará que não é possível definir a **depurar**, **compilação particular**, ou **especiais Crie** propriedades (na **propriedades** janela) para arquivos. RC:

- O **informações de versão** define o **depurar** propriedade com um `#ifdef` script de recurso, com base no `_DEBUG` sinalizador de compilação.

- Se o `Private Build` chave tem um **valor** definida **informações de versão** tabela correspondente **compilação particular** propriedade (no **propriedades**  janela) para o `FILEFLAGS` chave será **verdadeiro**. Se o **valor** estiver vazio, a propriedade será **falso**. Da mesma forma, o **compilação especial** chave (na **informações de versão** tabela) está vinculado ao **Build especial** propriedade para o `FILEFLAGS` chave.

Você pode classificar a sequência de informações do bloco de cadeia de caracteres, clicando em qualquer um de **chave** ou o **valor** títulos de coluna. Esses títulos de reorganizar automaticamente as informações na sequência selecionada.

### <a name="to-add-version-information-for-another-language-new-version-info-block"></a>Para adicionar informações de versão para outro idioma (novo bloco de informações de versão)

1. Abrir um recurso de informações de versão clicando duas vezes no [exibição de recurso](../windows/resource-view-window.md).

1. Clique dentro da tabela de informações de versão e escolha **novo bloco de informações de versão** no menu de atalho.

   Este comando adiciona um bloco de informações adicionais para o recurso de informações de versão atual e abre suas propriedades correspondentes na [janela de propriedades](/visualstudio/ide/reference/properties-window).

1. No **propriedades** janela, escolha o idioma apropriado e do conjunto para o novo bloco de caracteres.

### <a name="to-delete-a-version-information-block"></a>Para excluir um bloco de informações de versão

1. Abra o recurso de informações de versão clicando duas vezes em seu ícone no [exibição de recurso](../windows/resource-view-window.md).

1. O cabeçalho de bloco que você deseja excluir e clique com o botão direito **Excluir Bloco de informações de versão** no menu de atalho.

   Esse comando exclui o cabeçalho selecionado e deixa o restante das informações de versão intacta. Você não pode desfazer a ação.

### <a name="to-access-version-information-from-within-your-program"></a>Para acessar informações de versão do seu programa

Se você quiser acessar as informações de versão do seu programa, use o [GetFileVersionInfo](/windows/desktop/api/winver/nf-winver-getfileversioninfoa) função e o [VerQueryValue](/windows/desktop/api/winver/nf-winver-verqueryvaluea) função.

   > [!NOTE]
   > Ao usar o **informações de versão** editor, em muitos casos, pode clicar duas vezes para exibir um menu de atalho de comandos específicos ao recurso. Por exemplo, se você selecionar ao mesmo tempo, que aponta para uma entrada de cabeçalho do bloco, o menu de atalho mostra a **novas informações de versão de bloco** e **excluir informações de versão de bloco** comandos.

## <a name="requirements"></a>Requisitos

Win32

## <a name="see-also"></a>Consulte também

[Editores de recursos](../windows/resource-editors.md)<br/>
[Menus e outros recursos](https://msdn.microsoft.com/library/windows/desktop/ms632583.aspx)<br/>
[Informações de versão (Windows)](https://msdn.microsoft.com/library/windows/desktop/ms646981.aspx)
