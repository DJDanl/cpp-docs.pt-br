---
title: "Windows Forms/diferen&#231;as de programa&#231;&#227;o MFC | Microsoft Docs"
ms.custom: ""
ms.date: "12/14/2016"
ms.prod: "visual-studio-dev14"
ms.reviewer: ""
ms.suite: ""
ms.technology: 
  - "devlang-cpp"
ms.tgt_pltfrm: ""
ms.topic: "article"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "MFC [C++], suporte ao Windows Forms"
  - "Windows Forms [C++], em comparação com MFC"
ms.assetid: f3bfcf45-cfd4-45a4-8cde-5f4dbb18ee51
caps.latest.revision: 14
caps.handback.revision: 14
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# Windows Forms/diferen&#231;as de programa&#231;&#227;o MFC
[!INCLUDE[vs2017banner](../assembler/inline/includes/vs2017banner.md)]

Os tópicos em [Usando um controle de usuário do Windows Form no MFC](../dotnet/using-a-windows-form-user-control-in-mfc.md) descrevem o suporte de MFC do Windows Forms.  Se você não estiver familiarizado com o.NET Framework ou a programação de MFC, este tópico fornece informações gerais sobre diferenças de programação entre os dois.  
  
 O Windows Forms estiver criando aplicativos do Microsoft Windows no.NET Framework.  Essa estrutura fornece um conjunto moderno, orientado por objeto, extensível de classes que permitem desenvolver aplicativos baseados no Windows avançados.  Com o Windows Forms, você pode criar um aplicativo de cliente avançado que pode acessar uma ampla variedade de fontes de dados e fornecer recursos da exibição e da edição usando controles do Windows Forms.  
  
 No entanto, se você estiver acostumado ao MFC, você pode ser usado para criar determinados tipos de aplicativos que não são suportados ainda explicitamente no Windows Forms.  Os aplicativos do Windows Forms são equivalentes a aplicativos da caixa de diálogo MFC.  No entanto, não fornecem a infraestrutura diretamente para dar suporte a outros tipos de aplicativo MFC como o servidor OLE do documento\/contêineres, os documentos ActiveX, o suporte do documento\/exibição para a interface \(SDI\) de um único documento, a interface documentos \(MDI\), e a interface de nível superior de vários MTI \(\).  Você pode escrever sua própria lógica para criar esses aplicativos.  
  
 Para obter mais informações sobre os aplicativos do Windows Forms, consulte [Introdução ao Windows Forms](../Topic/Windows%20Forms%20Overview.md).  
  
 Para obter um aplicativo de exemplo que mostre o Windows Forms usado com o MFC, consulte [MFC e integração do Windows Forms](http://www.microsoft.com/downloads/details.aspx?FamilyID=987021bc-e575-4fe3-baa9-15aa50b0f599&displaylang=en).  
  
 Os seguintes recursos de roteamento de exibição ou do documento e do comando MFC não têm nenhum equivalente no Windows Forms:  
  
-   Integração de Shell  
  
     MFC O trata os comandos e os argumentos de linha de comando \(DDE\) de troca dinâmicas de dados que usa o shell quando você clica com o botão direito do mouse em um documento e selecione verbos como Abrir, os edita, ou os imprime.  O Windows Forms não tem nenhuma integração do shell e não responde a verbos shell.  
  
-   Modelos do documento  
  
     MFC no, os modelos do documento associam uma exibição, contida em uma janela do quadro \(no modo MDI, de SDI, ou de MTI\), com o documento que você abriu.  O Windows Forms não tem nenhum equivalente para documentar modelos.  
  
-   Documentos  
  
     Os registros de MFC documentam tipos de arquivo e processos o tipo de documento ao abrir um documento shell.  O Windows Forms não tem suporte do documento.  
  
-   Estados de documento  
  
     MFC O mantém estados sujos para o documento.  Em virtude disso, quando você fecha o aplicativo, feche à última exibição que contém o aplicativo, ou a saída do windows, MFC solicitará que você salve o documento.  O Windows Forms não tem nenhum equivalente suporte.  
  
-   Comandos  
  
     O MFC tem o conceito de comandos.  Todos a barra de menus, a barra de ferramentas, e o menu de contexto podem invocar o mesmo comando, por exemplo, divisão e impressão.  No Windows Forms, comandos são eventos com segurança associados de um elemento específico de interface do usuário \(como um item de menu\); consequentemente, é necessário conectar acima de todos os eventos de comando explicitamente.  Você também pode tratar vários eventos com um único manipulador no Windows Forms.  Para obter mais informações, consulte [Conectando vários eventos a um único manipulador de eventos do Windows Forms](../Topic/How%20to:%20Connect%20Multiple%20Events%20to%20a%20Single%20Event%20Handler%20in%20Windows%20Forms.md).  
  
-   Roteamento de comando  
  
     O roteamento do comando MFC habilita a exibição ativa ou o documento para processar comandos.  Como o mesmo comando tem frequentemente significados diferentes para exibições diferentes \(por exemplo, a cópia se comporta de modo diferente na exibição de edição de texto do que em um editor de gráficos\), os comandos precisam ser tratados pela exibição ativa.  Como os menus e barras de ferramentas do Windows Forms têm a compreensão não inerentemente da exibição ativa, você não pode ter um manipulador diferente para cada tipo de exibição para os eventos de **MenuItem.Click** sem gravar o código interno adicional.  
  
-   Mecanismo de atualização de comando  
  
     O MFC tem um mecanismo de atualização do comando.  Consequentemente, a exibição ativa ou o documento é responsável para o estado dos elementos de interface do usuário \(por exemplo, habilitar ou desabilitar um botão do item de menu ou da ferramenta, e estados verificados\).  O Windows Forms não tem nenhum equivalente de um mecanismo de atualização do comando.  
  
## Consulte também  
 [Usando um controle de usuário do Windows Form no MFC](../dotnet/using-a-windows-form-user-control-in-mfc.md)   
 [Windows Forms Walkthroughs](http://msdn.microsoft.com/pt-br/fd44d13d-4733-416f-aefc-32592e59e5d9)