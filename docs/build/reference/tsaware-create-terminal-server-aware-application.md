---
title: /TSAWARE (criar aplicativo com reconhecimento do Terminal Server)
ms.date: 11/04/2016
f1_keywords:
- /tsaware
- VC.Project.VCLinkerTool.TerminalServerAware
helpviewer_keywords:
- Terminal Server
- /TSAWARE linker option
- Terminal Server, Terminal Server-aware applications
- -TSAWARE linker option
- TSAWARE linker option
ms.assetid: fe1c1846-de5b-4839-b562-93fbfe36cd29
ms.openlocfilehash: 0b3fa8bcfd973949e73fdf701db2adb6c58be687
ms.sourcegitcommit: 2f9ff2041d70c406df76c5053151192aad3937ea
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/29/2020
ms.locfileid: "82587388"
---
# <a name="tsaware-create-terminal-server-aware-application"></a>/TSAWARE (criar aplicativo com reconhecimento do Terminal Server)

```
/TSAWARE[:NO]
```

## <a name="remarks"></a>Comentários

A opção/TSAWARE define um sinalizador no campo IMAGE_OPTIONAL_HEADER DllCharacteristics no cabeçalho opcional da imagem do programa. Quando esse sinalizador estiver definido, o servidor Host da Sessão da Área de Trabalho Remota não fará certas alterações no aplicativo.

Quando um aplicativo não está Terminal Server ciente (também conhecido como um aplicativo herdado), Terminal Server faz determinadas modificações no aplicativo herdado para fazê-lo funcionar corretamente em um ambiente multiusuário. Por exemplo, Terminal Server criará uma pasta virtual do Windows, de modo que cada usuário obtenha uma pasta do Windows em vez de obter o diretório do Windows do sistema. Isso permite que os usuários acessem seus próprios arquivos INI. Além disso, Terminal Server faz alguns ajustes no registro para um aplicativo herdado. Essas modificações reduzem o carregamento do aplicativo herdado no Terminal Server.

Se um aplicativo estiver Terminal Server ciente, ele não deverá depender de arquivos INI nem gravar no registro de **HKEY_CURRENT_USER** durante a instalação.

Se você usar o/TSAWARE e seu aplicativo ainda usar arquivos INI, os arquivos serão compartilhados por todos os usuários do sistema. Se isso for aceitável, você ainda poderá vincular seu aplicativo ao/TSAWARE; caso contrário, você precisará usar/TSAWARE: NO.

A opção/TSAWARE é habilitada por padrão para aplicativos do Windows e de console. Consulte [/Subsystem](subsystem-specify-subsystem.md) e [/version](version-version-information.md) para obter informações.

/TSAWARE não é válido para drivers ou DLLs.

Se um aplicativo tiver sido vinculado com/TSAWARE, DUMPBIN [/Headers](headers.md) exibirá informações para esse efeito.

### <a name="to-set-this-linker-option-in-the-visual-studio-development-environment"></a>Para definir esta opção do vinculador no ambiente de desenvolvimento do Visual Studio

1. Abra a caixa de diálogo **Páginas de Propriedades** do projeto. Para obter detalhes, confira [Definir as propriedades de build e do compilador do C++ no Visual Studio](../working-with-project-properties.md).

1. Clique na pasta **Vinculador**.

1. Clique na página de propriedades do **sistema** .

1. Modifique a propriedade **Terminal Server** .

### <a name="to-set-this-linker-option-programmatically"></a>Para definir esta opção do vinculador por meio de programação

- Consulte <xref:Microsoft.VisualStudio.VCProjectEngine.VCLinkerTool.TerminalServerAware%2A>.

## <a name="see-also"></a>Confira também

[Referência de vinculador MSVC](linking.md)<br/>
[Opções de vinculador MSVC](linker-options.md)<br/>
[Armazenando informações específicas do usuário](/windows/win32/TermServ/storing-user-specific-information)<br/>
[Aplicativos herdados em um ambiente de serviços de terminal](https://msdn.microsoft.com/library/aa382957.aspx)
