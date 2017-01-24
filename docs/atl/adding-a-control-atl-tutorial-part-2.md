---
title: "Adicionando um controle (Tutorial ATL, parte 2) | Microsoft Docs"
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
ms.assetid: c9575a75-1064-41f1-9697-7aada560c669
caps.latest.revision: 15
caps.handback.revision: 10
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# Adicionando um controle (Tutorial ATL, parte 2)
[!INCLUDE[vs2017banner](../assembler/inline/includes/vs2017banner.md)]

Nesta etapa, você adicionará um controle ao seu projeto, vai compilá\-lo e testá\-lo em uma página da Web.  
  
## Procedimentos  
  
#### Para adicionar um objeto para um projeto ATL  
  
1.  Na Visualização de Classe, clique com o botão direito do mouse no projeto Polígono.  
  
2.  Aponte para **Adicionar** no menu de atalho, e clique em **Classe** no submenu.  
  
     A caixa de diálogo **Adicionar Classe** aparece.  As categorias diferentes do objeto são listadas na estrutura de árvore à esquerda.  
  
3.  Clique na pasta **ATL**.  
  
4.  Na lista de modelos à direita, selecione **Controle do ATL**.  Clique em **Adicionar**.  O Assistente do controle do ATL será aberto, e você poderá configurar o controle.  
  
5.  Digite `PolyCtl` como o nome curto e observe que os outros campos são concluídos automaticamente.  Não clique em **Concluir** ainda, porque você tem que fazer algumas alterações.  
  
 A página **Nomes** do Assistente do controle do ATL contém os seguintes campos:  
  
|Campo|Sumário|  
|-----------|-------------|  
|**Nome curto**|O nome que você inseriu para o controle.|  
|**Classe**|O nome da classe C\+\+ criado para implementar o controle.|  
|**arquivo .h**|O arquivo criado para conter a definição da classe C\+\+.|  
|**arquivo .cpp**|O arquivo criado para conter a implementação da classe C\+\+.|  
|**CoClass**|O nome da classe componente desse controle.|  
|**Interface**|O nome da interface em que o controle implementará seus métodos e propriedades personalizados.|  
|**Tipo**|Uma descrição para o controle.|  
|**ProgID**|O nome legível que pode ser usado para procurar o CLSID do controle.|  
  
 Você tem que fazer várias configurações adicionais no Assistente do Controle do ATL.  
  
#### Para ativar o suporte para informações de erro e pontos de conexão ricos  
  
1.  Clique em **Opções** para abrir a página **Opções**.  
  
2.  Marque a caixa de seleção **Pontos de conexão**.  Isso criará o suporte para uma interface de saída no arquivo IDL.  
  
 Você também pode fazer o controle insertable, o que significa que ele pode ser inserido em aplicativos que suportam objetos inseridos, como o Excel ou Word.  
  
#### Para tornar o controle inserível  
  
1.  Clique em **Aparência** para abrir a página **Aparência**.  
  
2.  Marque a caixa de seleção **Inserível**.  
  
 O polígono exibido pelo objeto terá uma cor de preenchimento sólida, portanto, você precisa adicionar uma propriedade de estoque `Fill Color`.  
  
#### Para adicionar uma Cor de preenchimento armazene a propriedade e crie o controle  
  
1.  Clique em **Propriedades do Estoque** para abrir a página **Propriedades do Estoque**.  
  
2.  Em **Sem Suporte**, role para baixo a lista de possíveis propriedades pré\-definidas.  Clique duas vezes em `Fill Color` para movê\-lo para a lista **Com Suporte**.  
  
3.  Isso conclui as opções para o controle.  Clique em **Concluir**.  
  
 Como o assistente criou o controle, várias alterações de código e adições do arquivo ocorreram.  Os seguintes arquivos foram criados:  
  
|Arquivo|Descrição|  
|-------------|---------------|  
|PolyCtl.h|Contém a maior parte da implementação da classe `CPolyCtl` do C\+\+.|  
|PolyCtl.cpp|Contém as partes restantes de de `CPolyCtl`.|  
|PolyCtl.rgs|Um arquivo de texto que contém o script de registro usado para registrar o controle.|  
|PolyCtl.htm|Uma página da Web que contém uma referência ao controle recém\-criado.|  
  
 O assistente também executou as seguintes alterações de código:  
  
-   Adicionou uma declaração de `#include` aos arquivos stdafx.h e stdafx.cpp para incluir os arquivos de ATL necessários para oferecer suporte aos controles.  
  
-   Polygon.idl foi alterado para incluir detalhes do novo controle.  
  
-   Adicione o novo controle no mapa de objeto em Polygon.cpp.  
  
 Agora você pode compilar o controle para vê\-lo ação.  
  
## Compilando e testando o controle  
  
#### Para compilar e testar o controle  
  
1.  No menu **Compilar**, clique em **Compilar Polígono**.  
  
     Assim que o controle concluir a compilação, clique com o botão direito do mouse em PolyCtl.htm, no **Gerenciador de Soluções** e seleciona **Exibir no Navegador**.  A página da Web HTML que contém o controle será exibida.  Você deve ver uma página com o título de “página de teste ATL 8.0 para o objeto PolyCtl” e o texto **PolyCtl**.  Este é o seu controle.  
  
> [!NOTE]
>  Ao concluir este tutorial, se você receber uma mensagem de erro onde o arquivo DLL não pode ser criado, feche o arquivo de PolyCtl.htm e o recipiente de teste do controle ActiveX e crie a solução novamente.  Se você ainda não puder criar a DLL, reinicialize o computador ou faça logoff \(se estiver usando os Serviços de Terminal\).  
  
 Em seguida, você adicionará uma propriedade personalizada ao controle.  
  
 [Volte para a etapa 1](../atl/creating-the-project-atl-tutorial-part-1.md) &#124; [Na Etapa 3](../atl/adding-a-property-to-the-control-atl-tutorial-part-3.md)  
  
## Consulte também  
 [Tutorial](../Topic/Active%20Template%20Library%20\(ATL\)%20Tutorial.md)