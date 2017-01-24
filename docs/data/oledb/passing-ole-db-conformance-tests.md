---
title: "Passando testes de conformidade de banco de dados OLE | Microsoft Docs"
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
  - "teste de conformidade"
  - "teste de conformidade [OLE DB]"
  - "Provedores OLE DB, testando"
  - "testando provedores"
  - "testando, Provedores OLE DB"
ms.assetid: d1a4f147-2edd-476c-b452-0e6a0ac09891
caps.latest.revision: 7
caps.handback.revision: 7
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# Passando testes de conformidade de banco de dados OLE
[!INCLUDE[vs2017banner](../../assembler/inline/includes/vs2017banner.md)]

Para fazer provedores mais consistentes, o SDK do data access fornece um conjunto de testes de conformidade do OLE DB.  Os testes verificação de todos os aspectos do provedor e oferecem a segurança razoável o seu provedor funções como esperado.  Você pode localizar os testes de conformidade de OLE DB no acesso a dados SDK do Microsoft.  Esta seção aborda a coisas que você precisa fazer para passar os testes de conformidade.  Para obter informações sobre como executar testes de conformidade do OLE DB, consulte o SDK do.  
  
## Executando os testes de conformidade  
 No Visual C\+\+ 6.0, os modelos do provedor OLE DB adicionadas várias funções de suspensão com gancho para permitir que você verifique valores e propriedades.  A maioria dessas funções foram adicionadas em resposta a testes de conformidade.  
  
> [!NOTE]
>  Você precisa unir várias funções de validação para o provedor para passar os testes de conformidade do OLE DB.  
  
 Esse provedor exige duas rotinas de validação.  A primeira rotina, `CRowsetImpl::ValidateCommandID`, faz parte da sua classe do conjunto de linhas.  É chamada durante a criação do conjunto de linhas pelos modelos do provedor.  O exemplo usa esta rotina para informar a consumidores que não oferece suporte a índices.  A primeira chamada será `CRowsetImpl::ValidateCommandID` \(observe que o provedor usa o typedef de **\_RowsetBaseClass** adicionado no mapa da interface para `CMyProviderRowset` em [Suporte do provedor para indicadores](../../data/oledb/provider-support-for-bookmarks.md)portanto, não tem que digitar essa linha longa de argumentos de modelo\).  Em seguida, **DB\_E\_NOINDEX** de retorno se o parâmetro de índice não é **nulo** \(isso indica que o consumidor deseja usar um índice em nós\).  Para obter mais informações sobre as IDs de comando, consulte a especificação OLE DB e procure **IOpenRowset::OpenRowset**.  
  
 O código a seguir é uma rotina de validação de **ValidateCommandID** :  
  
```  
/////////////////////////////////////////////////////////////////////  
// MyProviderRS.H  
// Class: CMyProviderRowset   
  
HRESULT ValidateCommandID(DBID* pTableID, DBID* pIndexID)  
{  
   HRESULT hr = _RowsetBaseClass::ValidateCommandID(pTableID, pIndexID);  
   if (hr != S_OK)  
      return hr;  
  
   if (pIndexID != NULL)  
      return DB_E_NOINDEX;    // Doesn't support indexes  
  
   return S_OK;  
}  
```  
  
 Os modelos do provedor chamam o método de `OnPropertyChanged` sempre que alguém altera uma propriedade no grupo de **DBPROPSET\_ROWSET** .  Se você quiser tratar propriedades para outros grupos, adicione\-os ao objeto apropriado \(ou seja, as verificações de **DBPROPSET\_SESSION** vão da classe de `CMyProviderSession` \).  
  
 O código a seguir verifica primeiro para verificar se a propriedade está vinculada a outra.  Se a propriedade está sendo encadeada, defina a propriedade de **DBPROP\_BOOKMARKS** para retificar.  O apêndice C da especificação OLE DB contém informações sobre propriedades.  Essas informações também indica se a propriedade é encadeada a outra.  
  
 Você também pode desejar adicionar a rotina de `IsValidValue` ao seu código.  Os modelos chamam `IsValidValue` ao tentar definir uma propriedade.  Substitua esse método se você requer processamento extra ao definir um valor da propriedade.  Você pode ter um destes métodos para cada conjunto de propriedades.  
  
## Rosqueando problemas  
 Por padrão, o assistente do provedor OLE DB no assistente do provedor OLE DB de ATL gerencia o código para o provedor para execução em um modelo de. STA.  Se você tentar executar esse código com os testes de conformidade, você obtém inicialmente falhas.  Isso ocorre porque Ltm.exe, a ferramenta usada para executar a conformidade de OLE DB testa, assume como padrão para liberar rosqueado.  O código do assistente do provedor OLE DB usa como padrão o modelo de STA. para o desempenho e a facilidade de uso.  
  
 Para corrigir esse problema, você pode alterar o LTM ou alterar o provedor.  
  
#### Para alterar o LTM para execução em threaded o modo STA.  
  
1.  No menu principal de LTM, clique em **Ferramentas**, e clique em **Opções**.  
  
2.  Na guia de **Geral** , altere o modelo de threading de **Free Threaded** a **Apartment Threaded**.  
  
 Para alterar o provedor para execução no modo rosqueado livre:  
  
-   Em seu projeto do provedor, pesquise por todas as instâncias de `CComSingleThreadModel` e substitua\-o por `CComMultiThreadModel`, que devem estar em sua fonte de dados, sessão, e cabeçalhos de conjunto de linhas.  
  
-   Em seu arquivo de .rgs, altere o modelo de threading de **Apartment** a **Both**.  
  
-   Siga regras corretas de programação para a programação rosqueada livre \(ou seja, bloqueio em gravações\).  
  
## Consulte também  
 [Técnicas de provedor avançadas](../Topic/Advanced%20Provider%20Techniques.md)