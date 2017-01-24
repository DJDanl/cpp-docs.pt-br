---
title: "Testando o provedor somente leitura simples | Microsoft Docs"
ms.custom: ""
ms.date: "12/03/2016"
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
  - "Provedores OLE DB, Chamando "
  - "Provedores OLE DB, testando"
  - "testando provedores"
  - "testando, Provedores OLE DB"
ms.assetid: e4aa30c1-391b-41f8-ac73-5270e46fd712
caps.latest.revision: 8
caps.handback.revision: 8
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# Testando o provedor somente leitura simples
[!INCLUDE[vs2017banner](../../assembler/inline/includes/vs2017banner.md)]

Para testar um provedor, é necessário um consumidor.  A ajuda se o consumidor pode combinar com o provedor.  Os modelos do consumidor OLE DB são um wrapper fino OLE DB e correspondem aos objetos COM o provedor.  Como a origem for enviada com os modelos do consumidor, é fácil depurar um provedor com eles.  Os modelos do consumidor também é uma maneira muito pequena e rápida de desenvolver aplicativos do consumidor.  
  
 O exemplo neste tópico cria um aplicativo do assistente de aplicativo MFC de opção para um consumidor de teste.  O aplicativo de teste é uma caixa de diálogo simples com o código do modelo do consumidor OLE DB adicionado.  
  
### Para criar o aplicativo de teste  
  
1.  No menu **Arquivo**, clique em **Novo** e em **Projeto**.  
  
2.  No painel tipos de projeto, selecione a pasta de **Projetos do Visual C\+\+** .  No painel modelos, **Aplicativo do MFC**selecione.  
  
3.  Para o nome de projeto, entre em **TestProv**, e clique em **OK**.  
  
     O assistente de aplicativo MFC é exibida.  
  
4.  Na página de **Tipo de Aplicativo** , **Dialog based**selecione.  
  
5.  Na página de **Recursos Avançados** , **Automação**selecione, e clique em **Concluir**.  
  
> [!NOTE]
>  O aplicativo não exigir suporte de automação se você adicionar **CoInitialize** em **CTestProvApp::InitInstance**.  
  
 Você pode exibir e editar a caixa de diálogo de TestProv \(\) IDD\_TESTPROV\_DIALOG selecionando\-a na exibição de recursos.  Colocar duas caixas de listagem, uma para cada cadeia de caracteres no conjunto de linhas, na caixa de diálogo.  Desativar a propriedade do tipo para as duas caixas de listagem pressionando ALT\+Enter quando uma caixa de listagem estiver selecionada, clicando na guia de **Estilos** , e desmarcando a caixa de seleção de **Classificar** .  Além disso, coloque um botão de **Executar** na caixa de diálogo para buscar o arquivo.  A caixa de diálogo concluída de TestProv deve ter duas caixas de listagem rotuladas a cadeia de caracteres “1 " e “cadeia de caracteres 2 ", respectivamente; também tem **OK**, **Cancelar**, e os botões de **Executar** .  
  
 Abra o arquivo de cabeçalho da classe da caixa de diálogo \(nesse caso TestProvDlg.h\).  Adicione o seguinte código para o arquivo de cabeçalho \(fora de qualquer declaração de classe\):  
  
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
  
 O código representa um registro de usuário que define quais colunas estarão no conjunto de linhas.  Quando o cliente chama **IAccessor::CreateAccessor**, usa essas entradas para especificar as colunas a ser associado.  Os modelos do consumidor OLE DB também permitem a você associar colunas dinamicamente.  Macros de COLUMN\_ENTRY é a versão do lado do cliente de macros de PROVIDER\_COLUMN\_ENTRY.  Os dois macros de COLUMN\_ENTRY especifica o ordinal, o tipo, comprimento, e o membro de dados para as duas cadeias de caracteres.  
  
 Adicionar uma função de manipulador para o botão de **Executar** pressionar CTRL e clicando duas vezes no botão de **Executar** .  Coloque o código a seguir na função:  
  
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
  
 `CCommand`, `CDataSource`, e as classes de todos `CSession` pertencem aos modelos do consumidor OLE DB.  Cada classe imita um objeto COM no provedor.  O objeto de `CCommand` usa a classe de `CProvider` , declarada no arquivo de cabeçalho, como um parâmetro do modelo.  O parâmetro de `CProvider` representa as associações que você usa para acessar os dados do provedor.  Segue o código de `Open` para a fonte de dados, a sessão, e o comando:  
  
```  
if (source.Open("MyProvider.MyProvider.1", NULL) != S_OK)  
   return;  
  
if (session.Open(source) != S_OK)  
   return;  
  
if (table.Open(session, _T("c:\\samples\\myprov\\myData.txt")) != S_OK)  
   return;  
```  
  
 As linhas para abrir cada uma das classes criam cada objeto no provedor.  Para localizar o provedor, use o PROGID do provedor.  Você pode obter ProgID do Registro do sistema ou examinando no arquivo de MyProvider.rgs \(abra o diretório e a pesquisa do provedor da chave de ProgID\).  
  
 O arquivo MyData.txt é incluído com o exemplo de MyProv.  Para criar um arquivo de seus próprios, usar um editor e digite um número par de cadeias de caracteres, pressionar ENTER entre cada cadeia de caracteres.  Alterar o nome do caminho se você mover o arquivo.  
  
 Passar a cadeia de caracteres “c:\\\\samples\\\\myprov\\\\MyData.txt" na linha de `table.Open` .  Se você etapas na chamada de `Open` , você verá que essa cadeia de caracteres é passada para o método de `SetCommandText` no provedor.  Observe que o método de `ICommandText::Execute` usou essa cadeia de caracteres.  
  
 Para buscar os dados, chame `MoveNext` na tabela.  `MoveNext` chama **IRowset::GetNextRows**, `GetRowCount`, e as funções de `GetData` .  Quando não houver mais nenhuma linha \(isto é, a posição atual no conjunto de linhas é maior que `GetRowCount`\), o loop será:  
  
```  
while (table.MoveNext() == S_OK)  
{  
   m_ctlString1.AddString(table.szField1);  
   m_ctlString2.AddString(table.szField2);  
}  
```  
  
 Observe que quando não houver mais nenhuma linha, os provedores retornam **DB\_S\_ENDOFROWSET**.  O valor de **DB\_S\_ENDOFROWSET** não é um erro.  Sempre verifique em `S_OK` para cancelar um loop de busca de dados e não usar a macro SUCEDIDO.  
  
 Agora você deve poder criar e testar o programa.  
  
## Consulte também  
 [Melhorando o provedor somente leitura simples](../../data/oledb/enhancing-the-simple-read-only-provider.md)