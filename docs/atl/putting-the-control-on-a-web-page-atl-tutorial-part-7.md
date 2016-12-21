---
title: "Colocando o controle em uma p&#225;gina da Web (Tutorial ATL, parte 7) | Microsoft Docs"
ms.custom: ""
ms.date: "12/03/2016"
ms.prod: "visual-studio-dev14"
ms.reviewer: ""
ms.suite: ""
ms.technology: 
  - "devlang-cpp"
ms.tgt_pltfrm: ""
ms.topic: "get-started-article"
dev_langs: 
  - "C++"
ms.assetid: 50dc4c95-c95b-4006-b88a-9826f7bdb222
caps.latest.revision: 15
caps.handback.revision: 10
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# Colocando o controle em uma p&#225;gina da Web (Tutorial ATL, parte 7)
[!INCLUDE[vs2017banner](../assembler/inline/includes/vs2017banner.md)]

O controle é concluído agora.  Para ver o controle funcionar em uma situação do mundo real, coloque\-o em uma página da Web.  Um arquivo HTML que contém o controle foi criado quando você definiu o seu controle.  Abra o arquivo PolyCtl.htm do **Gerenciador de Soluções** e será possível ver seu controle em uma página da Web.  
  
 Nesta etapa, você criará um script da página da Web para responder a eventos.  Você também irá alterar o controle para permitir que o Internet Explorer saiba que o controle é seguro para o script.  
  
## Para gerar um script da página da Web  
 O controle não faz nada ainda. Então, altere a página da Web para responder aos eventos que você envia.  
  
#### Para gerar um script da página da Web  
  
1.  Abra o PolyCtl.htm e selecione o modo HTML.  Adicione as seguintes linhas ao código HTML.  Elas devem ser adicionadas após `</OBJECT>`, mas antes de `</BODY>`.  
  
    ```  
  
    <SCRIPT LANGUAGE="VBScript">  
    <!--  
    Sub PolyCtl_ClickIn(x, y)  
       PolyCtl.Sides = PolyCtl.Sides + 1  
    End Sub  
    Sub PolyCtl_ClickOut(x, y)  
       PolyCtl.Sides = PolyCtl.Sides - 1  
    End Sub  
    -->  
    </SCRIPT>  
    ```  
  
2.  Salve o arquivo HTM.  
  
 Você adicionou código VBScript que obtém a propriedade dos lados do controle e aumenta o número de lados por um se você clicar no controle.  Se você clicar fora do controle, reduzirá o número de lados por um.  
  
## Indicando que o controle é seguro para o script  
 Você pode exibir a página da Web com o controle no Internet Explorer ou, mais conveniente, usar modo de navegador da Web compilada no Visual C\+\+.  Para ver seu controle no modo de navegador da Web, clique com o botão direito do mouse em PolyCtl.htm e clique em **Exibir no navegador**.  
  
 Com base em suas configurações de segurança atuais do Internet Explorer, você pode receber uma caixa de diálogo de alerta de segurança que indica que o controle não pode ser seguro para o script e pode potencialmente causar danos.  Por exemplo, se você tinha um controle que exibia um arquivo mas que também tinha um método `Delete` que excluía um arquivo, seria seguro se você simplesmente o exibisse em uma página.  No entanto, não seria seguro criar um script porque alguém poderia chamar o método `Delete`.  
  
> [!IMPORTANT]
>  Para este tutorial, você pode alterar suas configurações de segurança no Internet Explorer para executar controles ActiveX que não estejam marcados como seguros.  No Painel de Controle, clique em **Propriedades da Internet** e clique em **Segurança** para alterar as configurações apropriadas.  Quando tiver concluído o tutorial, altere suas configurações de segurança de volta para o estado original.  
  
 Você pode programaticamente alertar o Internet Explorer que ele não precisa exibir a caixa de diálogo de alerta de segurança para este controle específico.  Você pode fazer isso com a interface de `IObjectSafety` , e o ATL fornece uma implementação dessa interface na classe [IObjectSafetyImpl](../atl/reference/iobjectsafetyimpl-class.md).  Para adicionar a interface ao controle, adicione `IObjectSafetyImpl` a sua lista de classes herdadas e adicione uma entrada para ele no seu mapa COM.  
  
#### Para adicionar IObjectSafetyImpl ao controle  
  
1.  Adicione a seguinte linha no final da lista de classes herdadas em PolyCtl.h e adicione uma vírgula na linha anterior:  
  
     [!code-cpp[NVC_ATL_Windowing#62](../atl/codesnippet/CPP/putting-the-control-on-a-web-page-atl-tutorial-part-7_1.h)]  
  
2.  Adicione as linhas a seguir ao mapa COM em PolyCtl.h:  
  
     [!code-cpp[NVC_ATL_Windowing#63](../atl/codesnippet/CPP/putting-the-control-on-a-web-page-atl-tutorial-part-7_2.h)]  
  
## Compilando e testando o controle  
 Compilar o controle.  Assim que a compilação é concluída, abra o PolyCtl.htm no modo de navegador novamente.  Desta vez, a página da Web deve ser exibida diretamente sem a caixa de diálogo Alerta de Segurança.  Clique dentro do polígono; o número de lados aumenta em um.  Clique fora do polígono para reduzir o número de lados.  Se você tentar reduzir o número de lados para abaixo de três, verá a mensagem de erro definida.  
  
 [Volte para a etapa 6](../Topic/Adding%20a%20Property%20Page%20\(ATL%20Tutorial,%20Part%206\).md)  
  
## Próximas etapas  
 Isso conclui o tutorial do ATL.  Para obter links para mais informações sobre o ATL, consulte a [página inicial do ATL](../atl/active-template-library-atl-concepts.md).  
  
## Consulte também  
 [Tutorial](../Topic/Active%20Template%20Library%20\(ATL\)%20Tutorial.md)