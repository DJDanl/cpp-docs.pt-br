---
title: Diferenças de programação de MFC de formulários do Windows | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-cli
ms.topic: conceptual
dev_langs:
- C++
helpviewer_keywords:
- MFC [C++], Windows Forms support
- Windows Forms [C++], compared to MFC
ms.assetid: f3bfcf45-cfd4-45a4-8cde-5f4dbb18ee51
author: mikeblome
ms.author: mblome
ms.workload:
- cplusplus
- dotnet
ms.openlocfilehash: 9ad9e47ba2bb3d9a5e5b21620a4bf4b50177d63b
ms.sourcegitcommit: 76b7653ae443a2b8eb1186b789f8503609d6453e
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 05/04/2018
---
# <a name="windows-formsmfc-programming-differences"></a>Windows Forms/diferenças de programação MFC
Os tópicos [usando um controle de usuário do Windows Form no MFC](../dotnet/using-a-windows-form-user-control-in-mfc.md) descrevem o suporte do MFC para formulários do Windows. Se você não estiver familiarizado com o .NET Framework ou MFC de programação, este tópico fornece informações básicas sobre programação diferenças entre os dois.  
  
 Windows Forms é para a criação de aplicativos do Microsoft Windows no .NET Framework. Essa estrutura fornece um conjunto moderno, orientada a objeto e extensível de classes que permitem desenvolver aplicativos avançados baseados em Windows. Com o Windows Forms, será capaz de criar um aplicativo cliente avançado que pode acessar uma ampla variedade de fontes de dados e fornecer recursos de edição de dados usando controles de formulários do Windows e de exibição de dados.  
  
 No entanto, se você estiver acostumado a MFC, pode ser usado para a criação de certos tipos de aplicativos que ainda não são explicitamente aceitas em formulários do Windows. Aplicativos de formulários do Windows são equivalentes aos aplicativos de caixa de diálogo do MFC. No entanto, eles não fornecer a infraestrutura para dar suporte diretamente a outros tipos de aplicativos MFC como servidor/contêiner de documento OLE, documentos ActiveX, o suporte a exibição de documentos para a interface de documento único (SDI), a interface de documentos múltiplos (MDI), e interface de nível superior múltiplos (MTI). Você pode escrever sua própria lógica para criar esses aplicativos.  
  
 Para obter mais informações sobre aplicativos de formulários do Windows, consulte [Introdução ao Windows Forms](/dotnet/framework/winforms/windows-forms-overview).  
  
 Para um aplicativo de exemplo que mostra usado com MFC de formulários do Windows, consulte [MFC e integração de formulários do Windows](http://www.microsoft.com/downloads/details.aspx?FamilyID=987021bc-e575-4fe3-baa9-15aa50b0f599&displaylang=en).  
  
 A seguinte exibição MFC ou documento e recursos de roteamento de comando não têm equivalentes no Windows Forms:  
  
-   Integração com o shell  
  
     MFC lida com os comandos de intercâmbio (DDE) de dados dinâmicos e argumentos de linha de comando que o shell usa ao clique de um documento e selecione tais verbos como abrir, editar ou imprimir. Windows Forms não tem nenhuma integração com o shell e não responde aos verbos de shell.  
  
-   Modelos de documento  
  
     Em MFC, modelos de documento associar uma exibição, que está contida em uma janela do quadro (no modo MDI, SDI ou MTI), o documento que é aberto. Windows Forms não tem nenhum equivalente para modelos de documento.  
  
-   Documentos  
  
     MFC registra tipos de arquivo de documento e processa o tipo de documento ao abrir um documento do shell. Windows Forms tem suporte documento.  
  
-   Estados de documento  
  
     MFC mantém estados incorretos para o documento. Portanto, quando você fecha o aplicativo, feche o último modo de exibição que contém o aplicativo ou sair do Windows, MFC avisa para salvar o documento. Windows Forms tem suporte equivalente.  
  
-   Comandos  
  
     MFC tem o conceito de comandos. A barra de menus, a barra de ferramentas e o menu de contexto podem invocar o mesmo comando, por exemplo, recortar e copiar. No Windows Forms, comandos estão estreitamente acoplados eventos de um determinado elemento de interface do usuário (como um item de menu); Portanto, você precisa conectar todos os eventos de comando explicitamente. Você também pode manipular vários eventos com um único manipulador em formulários do Windows. Para obter mais informações, consulte [conectar vários eventos a um único manipulador de eventos em formulários do Windows](/dotnet/framework/winforms/how-to-connect-multiple-events-to-a-single-event-handler-in-windows-forms).  
  
-   Roteamento de comando  
  
     Roteamento de comando do MFC habilita o modo de exibição ativo ou documento para comandos de processo. Como o mesmo comando geralmente tem significados diferentes para diferentes modos de exibição (por exemplo, cópia tem um comportamento diferente no modo de edição de texto que em um editor de elementos gráficos), os comandos precisam ser manipulados pelo modo de exibição ativo. Como as barras de ferramentas e menus de formulários do Windows não têm nenhuma compreensão inerente de modo de exibição ativo, você não pode ter um manipulador diferentes para cada tipo de exibição para seu **MenuItem.Click** eventos sem escrever código interno adicional.  
  
-   Mecanismo de atualização de comando  
  
     MFC possui um mecanismo de atualização. Portanto, o modo de exibição ativo ou o documento é responsável por estado dos elementos da interface do usuário (por exemplo, habilitar ou desabilitar um botão de ferramenta ou item de menu e verificada estados). Windows Forms não tem nenhum equivalente de um mecanismo de atualização de comando.  
  
## <a name="see-also"></a>Consulte também  
 [Usando um controle de usuário do Windows Form no MFC](../dotnet/using-a-windows-form-user-control-in-mfc.md)   
 [Instruções passo a passo dos Windows Forms](http://msdn.microsoft.com/en-us/fd44d13d-4733-416f-aefc-32592e59e5d9)