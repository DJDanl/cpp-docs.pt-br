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
ms.openlocfilehash: f6ed6184f8ae4b3a0f9db3c1f962a2918a185138
ms.sourcegitcommit: 8105b7003b89b73b4359644ff4281e1595352dda
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 03/14/2019
ms.locfileid: "57816939"
---
# <a name="tsaware-create-terminal-server-aware-application"></a>/TSAWARE (criar aplicativo com reconhecimento do Terminal Server)

```
/TSAWARE[:NO]
```

## <a name="remarks"></a>Comentários

A opção /TSAWARE define um sinalizador no campo IMAGE_OPTIONAL_HEADER DllCharacteristics no cabeçalho opcional da imagem do programa. Quando esse sinalizador estiver definido, o servidor Host da Sessão da Área de Trabalho Remota não fará certas alterações no aplicativo.

Quando um aplicativo não é Terminal Server aware (também conhecido como um aplicativo herdado), o servidor de Terminal faz algumas modificações para o aplicativo herdado para fazê-lo funcionar corretamente em um ambiente multiusuário. Por exemplo, o Terminal Server criará uma pasta virtual do Windows, de modo que cada usuário obtém uma pasta do Windows em vez de obter o diretório do Windows do sistema. Isso fornece aos usuários acesso aos seus próprios arquivos INI. Além disso, o servidor de Terminal faz alguns ajustes para o registro para um aplicativo herdado. Essas modificações o carregamento lento do aplicativo herdado no servidor de Terminal.

Se um aplicativo está ciente do Terminal Server, ele deve contar com arquivos INI nem gravar o **HKEY_CURRENT_USER** registro durante a instalação.

Se você usar /TSAWARE e seu aplicativo ainda usa arquivos INI, os arquivos serão compartilhados por todos os usuários do sistema. Se for aceitável, você ainda pode vincular seu aplicativo com /TSAWARE; Caso contrário, você precisará usar /TSAWARE: no.

A opção /TSAWARE é habilitada por padrão para Windows e aplicativos de console. Ver [/SUBSYSTEM](subsystem-specify-subsystem.md) e [/VERSION](version-version-information.md) para obter informações.

/TSAWARE não é válido para drivers, VxDs ou DLLs.

Se um aplicativo foi vinculado com /TSAWARE, DUMPBIN [/HEADERS](headers.md) exibirá informações sobre isso.

### <a name="to-set-this-linker-option-in-the-visual-studio-development-environment"></a>Para definir esta opção do vinculador no ambiente de desenvolvimento do Visual Studio

1. Abra a caixa de diálogo **Páginas de Propriedades** do projeto. Para obter detalhes, consulte [propriedades de compilador e de build definida C++ no Visual Studio](../working-with-project-properties.md).

1. Clique o **vinculador** pasta.

1. Clique o **sistema** página de propriedades.

1. Modificar a **Terminal Server** propriedade.

### <a name="to-set-this-linker-option-programmatically"></a>Para definir esta opção do vinculador por meio de programação

- Consulte <xref:Microsoft.VisualStudio.VCProjectEngine.VCLinkerTool.TerminalServerAware%2A>.

## <a name="see-also"></a>Consulte também

[Referência de vinculador MSVC](linking.md)<br/>
[Opções do vinculador MSVC](linker-options.md)<br/>
[Armazenar informações específicas do usuário](/windows/desktop/TermServ/storing-user-specific-information)<br/>
[Aplicativos herdados em um ambiente de serviços de Terminal](https://msdn.microsoft.com/library/aa382957.aspx)
