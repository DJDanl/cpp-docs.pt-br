---
title: Diferenças de programação do Windows Forms MFC
ms.date: 11/04/2016
helpviewer_keywords:
- MFC [C++], Windows Forms support
- Windows Forms [C++], compared to MFC
ms.assetid: f3bfcf45-cfd4-45a4-8cde-5f4dbb18ee51
ms.openlocfilehash: 136549bb457cc17293d4c7201c9836d9094eea94
ms.sourcegitcommit: e5192a25c084eda9eabfa37626f3274507e026b3
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 11/12/2019
ms.locfileid: "73965548"
---
# <a name="windows-formsmfc-programming-differences"></a>Windows Forms/diferenças de programação MFC

Os tópicos em [usando um controle de usuário do Windows Form no MFC](../dotnet/using-a-windows-form-user-control-in-mfc.md) descrevem o suporte do MFC para Windows Forms. Se você não estiver familiarizado com a programação .NET Framework ou MFC, este tópico fornecerá informações básicas sobre diferenças de programação entre os dois.

Windows Forms é para criar aplicativos do Microsoft Windows no .NET Framework. Essa estrutura fornece um conjunto de classes moderno e orientado a objeto, extensível, que permite desenvolver aplicativos avançados baseados no Windows. Com o Windows Forms, você pode criar um aplicativo cliente avançado que possa acessar uma ampla variedade de fontes de dados e fornecer recursos de exibição de dados e edição de dados usando controles Windows Forms.

No entanto, se você estiver acostumado com o MFC, poderá ser usado para criar determinados tipos de aplicativos que ainda não têm suporte explícito no Windows Forms. Windows Forms aplicativos são equivalentes aos aplicativos de diálogo do MFC. No entanto, eles não fornecem a infraestrutura para dar suporte direto a outros tipos de aplicativos MFC, como servidor de documentos OLE/contêiner, documentos ActiveX, suporte de documento/exibição para SDI (interface de documento único), MDI (interface de vários documentos) e várias interfaces de nível superior (MTI). Você pode escrever sua própria lógica para criar esses aplicativos.

Para obter mais informações sobre Windows Forms aplicativos, consulte [introdução ao Windows Forms](/dotnet/framework/winforms/windows-forms-overview).

Para um aplicativo de exemplo que mostra Windows Forms usado com MFC, consulte [integração do MFC e do Windows Forms](https://www.microsoft.com/download/details.aspx?id=2113).

O seguinte modo de exibição MFC ou recursos de roteamento de comando e documento não têm equivalentes no Windows Forms:

- Integração com o Shell

   O MFC lida com os comandos de intercâmbio dinâmico de dados (DDE) e os argumentos de linha de comando que o Shell usa quando você clica com o botão direito do mouse em um documento e seleciona esses verbos como abrir, editar ou imprimir. O Windows Forms não tem integração com o Shell e não responde aos verbos do Shell.

- Modelos de documento

   No MFC, os modelos de documento associam uma exibição, que está contida em uma janela de quadro (no modo MDI, SDI ou MTI), com o documento que você abriu. Windows Forms não tem nenhum equivalente aos modelos de documento.

- Documentos

   O MFC registra tipos de arquivo de documento e processa o tipo de documento ao abrir um documento do Shell. O Windows Forms não tem suporte a documentos.

- Estados do documento

   O MFC mantém Estados sujos para o documento. Portanto, quando você fechar o aplicativo, fechar a última exibição que contém o aplicativo ou sair do Windows, o MFC solicitará que você salve o documento. Windows Forms não tem suporte equivalente.

- Comandos

   O MFC tem o conceito de comandos. A barra de menus, a barra de ferramentas e o menu de contexto podem invocar o mesmo comando, por exemplo, recortar e copiar. No Windows Forms, os comandos são rigidamente ligados a eventos de um determinado elemento de interface do usuário (como um item de menu); Portanto, você precisa conectar todos os eventos de comando explicitamente. Você também pode manipular vários eventos com um único manipulador no Windows Forms. Para obter mais informações, consulte [conectando vários eventos a um único manipulador de eventos no Windows Forms](/dotnet/framework/winforms/how-to-connect-multiple-events-to-a-single-event-handler-in-windows-forms).

- Roteamento de comando

   O roteamento de comandos do MFC permite que o modo de exibição ou documento ativo processe comandos. Como o mesmo comando geralmente tem significados diferentes para diferentes exibições (por exemplo, a cópia se comporta de forma diferente na exibição de edição de texto do que em um editor de gráficos), os comandos precisam ser manipulados pelo modo de exibição ativo. Como Windows Forms menus e barras de ferramentas não têm compreensão inerente da exibição ativa, você não pode ter um manipulador diferente para cada tipo de exibição para seus eventos **MenuItem. Click** sem escrever código interno adicional.

- Mecanismo de atualização de comando

   O MFC tem um mecanismo de atualização de comando. Portanto, o documento ou modo de exibição ativo é responsável pelo Estado dos elementos da interface do usuário (por exemplo, habilitar ou desabilitar um item de menu ou botão de ferramenta e Estados marcados). Windows Forms não tem nenhum equivalente a um mecanismo de atualização de comando.

## <a name="see-also"></a>Consulte também

[Usando um controle de usuário do Windows Form no MFC](../dotnet/using-a-windows-form-user-control-in-mfc.md)
