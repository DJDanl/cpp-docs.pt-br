---
title: Testando o provedor somente leitura | Microsoft Docs
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology: cpp-windows
ms.tgt_pltfrm: 
ms.topic: article
dev_langs: C++
helpviewer_keywords:
- testing, OLE DB providers
- testing providers
- OLE DB providers, calling
- OLE DB providers, testing
ms.assetid: e4aa30c1-391b-41f8-ac73-5270e46fd712
caps.latest.revision: "8"
author: mikeblome
ms.author: mblome
manager: ghogen
ms.workload:
- cplusplus
- data-storage
ms.openlocfilehash: 438ab42a7f0f12379621a591f3b0b1eeb5930afd
ms.sourcegitcommit: 8fa8fdf0fbb4f57950f1e8f4f9b81b4d39ec7d7a
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 12/21/2017
---
# <a name="testing-the-read-only-provider"></a>Testando o provedor somente leitura simples
Para testar um provedor, você precisa de um consumidor. Isso será útil se o consumidor pode corresponder a com o provedor. Os modelos de consumidor OLE DB são um wrapper fino em torno do OLE DB e correspondem com os objetos COM do provedor. Como a fonte é fornecida com os modelos de consumidor, é fácil depurar um provedor com eles. Os modelos de consumidor também são uma maneira muito menor e mais rápida para desenvolver aplicativos de consumidor.  
  
 O exemplo neste tópico cria um aplicativo do Assistente de aplicativo MFC padrão para um consumidor de teste. O aplicativo de teste é uma caixa de diálogo com o código de modelo de consumidor OLE DB adicionado.  
  
### <a name="to-create-the-test-application"></a>Para criar o aplicativo de teste  
  
1.  No menu **Arquivo**, clique em **Novo** e clique em **Projeto**.  
  
2.  No painel de tipos de projeto, selecione o **projetos Visual C++** pasta. No painel de modelos, selecione **aplicativo MFC**.  
  
3.  Para o nome do projeto, insira **TestProv**e, em seguida, clique em **Okey**.  
  
     O Assistente de aplicativo MFC aparece.  
  
4.  Sobre o **tipo de aplicativo** página, selecione **caixa de diálogo com base em**.  
  
5.  Sobre o **recursos avançados** página, selecione **automação**e, em seguida, clique em **concluir**.  
  
> [!NOTE]
>  O aplicativo não exigir suporte de automação, se você adicionar **CoInitialize** na **CTestProvApp::InitInstance**.  
  
 Você pode exibir e editar a caixa de diálogo TestProv (IDD_TESTPROV_DIALOG), selecionando-o no modo de exibição de recursos. Coloque duas caixas de listagem, uma para cada cadeia de caracteres no conjunto de linhas, na caixa de diálogo. Desativar a propriedade de classificação para as caixas de listagem, pressionando ALT + Enter quando uma caixa de listagem é selecionada, clicar no **estilos** guia e limpar o **classificação** caixa de seleção. Além disso, coloque uma **executar** botão na caixa de diálogo para buscar o arquivo. A caixa de diálogo TestProv terminar deve ter duas caixas de listagem rotuladas "String 1" e "Cadeia de caracteres 2", respectivamente; Ele também tem **Okey**, **Cancelar**, e **executar** botões.  
  
 Abra o arquivo de cabeçalho para a caixa de diálogo classe (neste caso TestProvDlg.h). Adicione o seguinte código para o arquivo de cabeçalho (fora de qualquer declaração de classe):  
  
```  
////////////////////////////////////////////////////////////////////////  
// TestProvDlg.h  
  
class CProvider   
{  
// Attributes  
public:  
   char   szField1[16];  
   char   szField2[16];  
  
   // Binding Maps  
BEGIN_COLUMN_MAP(CProvider)  
   COLUMN_ENTRY(1, szField1)  
   COLUMN_ENTRY(2, szField2)  
END_COLUMN_MAP()  
};  
```  
  
 O código representa um registro de usuário que define quais colunas serão no conjunto de linhas. Quando o cliente chama **IAccessor:: CreateAccessor**, ele usa essas entradas para especificar as colunas que deseja vincular. Os modelos de consumidor OLE DB também permitem que você associar colunas dinamicamente. As macros COLUMN_ENTRY são da versão do cliente da macro PROVIDER_COLUMN_ENTRY. As macros COLUMN_ENTRY dois especifiquem o ordinal, o membro de dados, comprimento e tipo de duas cadeias de caracteres.  
  
 Adicionar uma função de manipulador para o **executar** botão pressionando CTRL e clicando duas vezes o **executar** botão. Coloque o código a seguir na função:  
  
```  
///////////////////////////////////////////////////////////////////////  
// TestProvDlg.cpp  
  
void CtestProvDlg::OnRun()  
{  
   CCommand<CAccessor<CProvider> > table;  
   CDataSource source;  
   CSession   session;  
  
   if (source.Open("MyProvider.MyProvider.1", NULL) != S_OK)  
      return;  
  
   if (session.Open(source) != S_OK)  
      return;  
  
   if (table.Open(session, _T("c:\\samples\\myprov\\myData.txt")) != S_OK)  
      return;  
  
   while (table.MoveNext() == S_OK)  
   {  
      m_ctlString1.AddString(table.szField1);  
      m_ctlString2.AddString(table.szField2);  
   }  
}  
```  
  
 O `CCommand`, `CDataSource`, e `CSession` classes todas pertencem aos modelos de consumidor OLE DB. Cada classe imita a um objeto COM o provedor. O `CCommand` objeto leva o `CProvider` classe declarado no arquivo de cabeçalho, como um parâmetro de modelo. O `CProvider` parâmetro representa associações que você usa para acessar os dados do provedor. Aqui está o `Open` código para a fonte de dados, a sessão e o comando:  
  
```  
if (source.Open("MyProvider.MyProvider.1", NULL) != S_OK)  
   return;  
  
if (session.Open(source) != S_OK)  
   return;  
  
if (table.Open(session, _T("c:\\samples\\myprov\\myData.txt")) != S_OK)  
   return;  
```  
  
 As linhas para abrir cada uma das classes criam cada objeto COM no provedor. Para localizar o provedor, use o ProgID do provedor. Você pode obter o ProgID do registro do sistema ou examinando o arquivo MyProvider.rgs (Abra o diretório e a pesquisa para a chave ProgID do provedor).  
  
 O arquivo MyData.txt é incluído com o exemplo MyProv. Para criar um arquivo de sua preferência, use um editor e digite um número par de cadeias de caracteres, pressionando ENTER entre cada cadeia de caracteres. Se você mover o arquivo, altere o nome do caminho.  
  
 Passe a cadeia de caracteres "c:\\\samples\\\myprov\\\MyData.txt" no `table.Open` linha. Se você entrar o `Open` chamada, verá que essa cadeia de caracteres é passada para o `SetCommandText` método no provedor. Observe que o `ICommandText::Execute` método usado essa cadeia de caracteres.  
  
 Para buscar os dados, chame `MoveNext` na tabela. `MoveNext`chamadas de **GetNextRows**, `GetRowCount`, e `GetData` funções. Quando não houver mais nenhuma linha (ou seja, a posição atual no conjunto de linhas é maior do que `GetRowCount`), o loop será encerrado:  
  
```  
while (table.MoveNext() == S_OK)  
{  
   m_ctlString1.AddString(table.szField1);  
   m_ctlString2.AddString(table.szField2);  
}  
```  
  
 Observe que quando não houver mais nenhuma linha, os provedores retornar **DB_S_ENDOFROWSET**. O **DB_S_ENDOFROWSET** valor não é um erro. Você sempre deve verificar `S_OK` para cancelar um loop de busca de dados e não use a macro SUCCEEDED.  
  
 Agora você deve ser capaz de compilar e testar o programa.  
  
## <a name="see-also"></a>Consulte também  
 [Aprimorando o provedor somente leitura simples](../../data/oledb/enhancing-the-simple-read-only-provider.md)