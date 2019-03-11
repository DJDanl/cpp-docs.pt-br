---
title: Diferenças de programação do Windows Forms e o MFC
ms.date: 11/04/2016
helpviewer_keywords:
- MFC [C++], Windows Forms support
- Windows Forms [C++], compared to MFC
ms.assetid: f3bfcf45-cfd4-45a4-8cde-5f4dbb18ee51
ms.openlocfilehash: 998485a3384512f57cf35fc264e2321fa0996728
ms.sourcegitcommit: dedd4c3cb28adec3793329018b9163ffddf890a4
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 03/11/2019
ms.locfileid: "57742522"
---
# <a name="windows-formsmfc-programming-differences"></a>Windows Forms/diferenças de programação MFC

Os tópicos [usando um controle de usuário do Windows Form no MFC](../dotnet/using-a-windows-form-user-control-in-mfc.md) descrevem o suporte do MFC para formulários do Windows. Se você não estiver familiarizado com o .NET Framework ou MFC de programação, este tópico fornece informações básicas sobre programação diferenças entre os dois.

Windows Forms é para a criação de aplicativos do Microsoft Windows no .NET Framework. Essa estrutura fornece um conjunto moderno, orientada a objeto e extensível de classes que permitem desenvolver aplicativos avançados baseados em Windows. Com o Windows Forms, são capazes de criar um aplicativo cliente avançado que pode acessar uma ampla variedade de fontes de dados e fornecer recursos de edição de dados usando controles Windows Forms e de exibição de dados.

No entanto, se você estiver acostumado ao MFC, você pode ser usado para criar determinados tipos de aplicativos que ainda não são explicitamente suportados no Windows Forms. Aplicativos do Windows Forms são equivalentes aos aplicativos de caixa de diálogo do MFC. No entanto, eles não fornecem a infraestrutura para dar suporte diretamente a outros tipos de aplicativos MFC, como servidor/contêiner de documento OLE, documentos ActiveX, o suporte de documento/exibição para a interface de documento único (SDI), a interface de documentos múltiplos (MDI), e interface de nível superior múltiplos (MTI). Você pode escrever sua própria lógica para criar esses aplicativos.

Para obter mais informações sobre aplicativos do Windows Forms, consulte [Introdução ao Windows Forms](/dotnet/framework/winforms/windows-forms-overview).

Para um aplicativo de exemplo que mostra os formulários do Windows usado com o MFC, consulte [MFC e integração de formulários do Windows](http://www.microsoft.com/downloads/details.aspx?FamilyID=987021bc-e575-4fe3-baa9-15aa50b0f599&displaylang=en).

O seguinte modo de exibição do MFC ou documento e recursos de roteamento de comando não têm equivalentes no Windows Forms:

- Integração com o shell

   MFC manipula os comandos de DDE (troca) de dados dinâmicos e os argumentos de linha de comando que o shell usa quando um documento com o botão direito e selecione esses verbos como abrir, editar ou imprimir. Windows Forms não tem nenhuma integração com o shell e não responder a verbos de shell.

- Modelos de documento

   No MFC, modelos de documento associar um modo de exibição, que está contido em uma janela com moldura (no modo MDI, SDI ou MTI), o documento aberto. Formulários do Windows não tem nenhum equivalente para modelos de documento.

- Documentos

   MFC registra tipos de arquivo do documento e processa o tipo de documento ao abrir um documento do shell. Formulários do Windows tem suporte documento.

- Estados de documento

   MFC mantém sujos estados para o documento. Portanto, quando você fecha o aplicativo, feche a última exibição que contém o aplicativo ou sair do Windows, MFC solicitará que você salve o documento. Formulários do Windows tem suporte equivalente.

- Comandos

   MFC tem o conceito de comandos. A barra de menus, barra de ferramentas e menu de contexto podem invocar o mesmo comando, por exemplo, recortar e copiar. No Windows Forms, os comandos são rigidamente acoplados eventos de um determinado elemento de interface do usuário (por exemplo, um item de menu); Portanto, você precisa vincular explicitamente todos os eventos de comando. Você também pode manipular vários eventos com um único manipulador em formulários do Windows. Para obter mais informações, consulte [conectar vários eventos a um único manipulador de eventos nos Windows Forms](/dotnet/framework/winforms/how-to-connect-multiple-events-to-a-single-event-handler-in-windows-forms).

- Roteamento de comando

   Permite que o roteamento de comando do MFC, o modo de exibição ativo ou o documento para processar comandos. Como o mesmo comando geralmente tem significados diferentes para diferentes modos de exibição (por exemplo, cópia se comporta de forma diferente na exibição de edição de texto, que em um editor de gráficos), os comandos precisam ser manipulados pelo modo de exibição ativo. Como barras de ferramentas e menus de formulários do Windows têm não compreende inerente a exibição ativa, você não pode ter um manipulador diferentes para cada tipo de exibição para seu **MenuItem.Click** eventos sem escrever código interno adicional.

- Mecanismo de atualização de comando

   MFC possui um mecanismo de atualização. Portanto, o modo de exibição ativo ou o documento é responsável pelo estado dos elementos da interface do usuário (por exemplo, habilitar ou desabilitar um botão de ferramenta ou item de menu e verificada estados). Formulários do Windows não tem nenhum equivalente de um mecanismo de atualização de comando.

## <a name="see-also"></a>Consulte também

[Usando um controle de usuário do Windows Form no MFC](../dotnet/using-a-windows-form-user-control-in-mfc.md)
