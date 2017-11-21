---
title: Criando um consumidor simples | Microsoft Docs
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology: cpp-windows
ms.tgt_pltfrm: 
ms.topic: article
dev_langs: C++
helpviewer_keywords: OLE DB consumers, creating
ms.assetid: ae32d657-72ea-4db8-9839-75cb5cff68ae
caps.latest.revision: "7"
author: mikeblome
ms.author: mblome
manager: ghogen
ms.openlocfilehash: 9ab1066d9a1f56906fcbecca968da07b12a126c5
ms.sourcegitcommit: ebec1d449f2bd98aa851667c2bfeb7e27ce657b2
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 10/24/2017
---
# <a name="creating-a-simple-consumer"></a>Criando um consumidor simples
Use o Assistente de projeto de ATL e ATL OLE DB consumidor Assistente para gerar um consumidor de modelos OLE DB.  
  
#### <a name="to-create-a-console-application-for-an-ole-db-consumer"></a>Para criar um aplicativo de console para um consumidor OLE DB  
  
1.  No menu **Arquivo**, clique em **Novo** e clique em **Projeto**.  
  
     A caixa de diálogo **Novo Projeto** é exibida.  
  
2.  No painel de tipos de projeto, clique o **projetos Visual C++** pasta e, em seguida, clique o **projeto Win32** ícone no painel modelos. No **nome** , digite o nome do seu projeto, por exemplo, **MyCons**.  
  
3.  Clique em **OK**.  
  
     O Assistente de projeto Win32 é exibido.  
  
4.  Sobre o **configurações do aplicativo** página, selecione **aplicativo de Console**e, em seguida, selecione **adicionar suporte ATL**.  
  
5.  Clique em **concluir** para fechar o assistente e gerar o projeto.  
  
 Em seguida, use o Assistente de ATL OLE DB consumidor para adicionar um objeto de consumidor OLE DB.  
  
#### <a name="to-create-a-consumer-with-the-atl-ole-db-consumer-wizard"></a>Para criar um consumidor com o OLE DB consumidor assistente ATL  
  
1.  No modo de exibição de classe com o botão direito do `MyCons` projeto.  
  
2.  No menu de atalho, clique em **adicionar**e, em seguida, clique em **Adicionar classe**.  
  
     O **Adicionar classe** caixa de diálogo é exibida.  
  
3.  No painel de categorias, clique em **Visual C++**, clique no **ATL OLE DB consumidor** ícone no painel de modelos e, em seguida, clique **abrir**.  
  
     O OLE DB consumidor assistente ATL é exibida.  
  
4.  Clique o **fonte de dados** botão.  
  
     O **propriedades de vínculo de dados** caixa de diálogo é exibida.  
  
5.  No **propriedades de vínculo de dados** caixa de diálogo caixa, faça o seguinte:  
  
    -   Sobre o **provedor** guia, especifique um provedor OLE DB.  
  
    -   Sobre o **Conexão** guia, especifique o nome do servidor, a ID de logon e a senha para sua fonte de dados e o banco de dados no servidor.  
  
    > [!NOTE]
    >  Há um problema de segurança com o **permitir salvamento de senha** recurso do **propriedades de vínculo de dados** caixa de diálogo. Em **Insira informações para fazer logon no servidor**, há dois botões de opção: **a segurança integrada do Windows NT de uso** e **usar um determinado nome de usuário e senha**.  
  
    > [!NOTE]
    >  Se você selecionar **usar um determinado nome de usuário e senha**, você tem a opção de salvar a senha (usando o **permitir salvamento de senha** caixa de seleção); no entanto, essa opção não é segura. É recomendável que você selecione **a segurança integrada do Windows NT de uso**; essa opção usa o Windows NT para verificar sua identidade.  
  
    > [!NOTE]
    >  Se você não pode usar segurança integrada do Windows NT, você deve usar um aplicativo de camada intermediária para solicitar ao usuário a senha ou para armazenar a senha em um local com mecanismos de segurança para ajudar a protegê-lo (em vez de no código-fonte).  
  
     Depois de selecionar o provedor e outras configurações, clique em **Conexão de teste** para verificar se as seleções feitas nas páginas de caixa de diálogo anterior. Se o **resultados** caixa relatórios `Test connection succeeded`, clique em **Okey** para criar o link de dados.  
  
     O **Selecionar objeto de banco de dados** caixa de diálogo é exibida.  
  
6.  Use o controle de árvore para selecionar uma tabela, exibição ou procedimento armazenado. Para fins deste procedimento, selecione a tabela de produtos do banco de dados Northwind.  
  
7.  Clique em **OK**. Isso retorna ao Assistente de ATL OLE DB consumidor.  
  
8.  O assistente preenche os nomes para `Class` e **. h arquivo** com base no nome da tabela, exibição ou procedimento armazenado que você selecionou. Se desejar, você pode editar esses nomes.  
  
9. Limpar o **atribuída** caixa de seleção para que o assistente cria o código de consumidor usando [classes de modelo de banco de dados OLE](../../data/oledb/ole-db-consumer-templates-reference.md) em vez do padrão [atributos de consumidor OLE DB](../../windows/ole-db-consumer-attributes.md).  
  
10. Em **tipo**, selecione **comando**.  
  
     O assistente cria um [CCommand](../../data/oledb/ccommand-class.md)-com base em consumidor, se você selecionar **comando** ou um [CTable](../../data/oledb/ctable-class.md)-com base em consumidor, se você selecionar **tabela**. A classe de tabela ou o comando é nomeada após o objeto selecionado, mas você pode editar o nome.  
  
11. Em **suporte**, deixe o **alteração**, **inserir**, e **excluir** caixas desmarcadas.  
  
     Selecione o **alteração**, **inserir**, e **excluir** caixas de seleção para dar suporte a alteração, inserção e exclusão de registros no conjunto de linhas, se necessário. Para obter mais informações sobre a gravação de dados para os dados de armazenamento, consulte [atualizar conjuntos de linhas](../../data/oledb/updating-rowsets.md).  
  
12. Clique em **concluir** para criar o consumidor.  
  
 O assistente gera uma classe de comando e uma classe de registro de usuário, conforme mostrado no [Consumer Wizard-Generated Classes](../../data/oledb/consumer-wizard-generated-classes.md). A classe de comando terá o nome que você inseriu no `Class` caixa no Assistente (nesse caso, `CProducts`), e a classe de registro de usuário terá um nome no formato "*ClassName*acessador" (nesse caso, `CProductsAccessor`).  
  
> [!NOTE]
>  O assistente coloca Products.h a linha a seguir:  
  
```  
#error Security Issue: The connection string may contain a password  
```  
  
> [!NOTE]
>  Essa linha impede que o aplicativo de consumidor de compilação e lembrá-lo a cadeia de caracteres de conexão para senhas embutidas. Depois de verificar se a cadeia de conexão, você pode remover esta linha de código.  
  
## <a name="see-also"></a>Consulte também  
 [Criando um consumidor do OLE DB usando um assistente](../../data/oledb/creating-an-ole-db-consumer-using-a-wizard.md)