---
title: "CCommand::Open | Microsoft Docs"
ms.custom: ""
ms.date: "12/15/2016"
ms.prod: "visual-studio-dev14"
ms.reviewer: ""
ms.suite: ""
ms.technology: 
  - "devlang-cpp"
ms.tgt_pltfrm: ""
ms.topic: "article"
f1_keywords: 
  - "ATL.CCommand.Open"
  - "ATL::CCommand::Open"
  - "CCommand.Open"
  - "CCommand::Open"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "Método Open"
ms.assetid: 4c9b8f31-faf3-452d-9a29-3d3e5f54d6f8
caps.latest.revision: 10
caps.handback.revision: 10
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# CCommand::Open
[!INCLUDE[vs2017banner](../../assembler/inline/includes/vs2017banner.md)]

Executa e associa o comando.  
  
## Sintaxe  
  
```  
  
      HRESULT Open(  
   const CSession& session,  
   LPCWSTR wszCommand,  
   DBPROPSET *pPropSet = NULL,  
   DBROWCOUNT* pRowsAffected = NULL,  
   REFGUID guidCommand = DBGUID_DEFAULT,  
   bool bBind = true,  
   ULONG ulPropSets = 0  
) throw( );  
HRESULT Open(  
   const CSession& session,  
   LPCSTR szCommand,  
   DBPROPSET *pPropSet = NULL,  
   DBROWCOUNT* pRowsAffected = NULL,  
   REFGUID guidCommand = DBGUID_DEFAULT,  
   bool bBind = true,  
   ULONG ulPropSets = 0  
) throw( );  
HRESULT Open(  
   const CSession& session,  
   INT szCommand = NULL,  
   DBPROPSET *pPropSet = NULL,  
   DBROWCOUNT* pRowsAffected = NULL,  
   REFGUID guidCommand = DBGUID_DEFAULT,  
   bool bBind = true,  
   ULONG ulPropSets = 0  
) throw( );  
HRESULT Open(  
   DBPROPSET *pPropSet = NULL,  
   DBROWCOUNT* pRowsAffected = NULL,  
   bool bBind = true,  
   ULONG ulPropSets = 0  
) throw( );  
```  
  
#### Parâmetros  
 `session`  
 \[in\] a sessão na qual executar o comando.  
  
 `wszCommand`  
 \[in\] execução do comando, passado como uma cadeia de caracteres Unicode.  Pode ser **nulo** ao usar `CAccessor`nesse caso, o comando será recuperado do valor passado para a macro de [DEFINE\_COMMAND](../../data/oledb/define-command.md) .  Consulte [ICommand::Execute](https://msdn.microsoft.com/en-us/library/ms718095.aspx)*na referência do programador de OLE DB* para obter detalhes.  
  
 `szCommand`  
 \[in\] mesmo que `wszCommand` exceto que este parâmetro tem uma cadeia de caracteres de comando ANSI.  O quarto formulário desse método pode aceitar um valor NULO.  Consulte “comentários” posteriormente neste tópico para obter detalhes.  
  
 *pPropSet*  
 \[in\] o ponteiro da uma matriz de [DBPROPSET](https://msdn.microsoft.com/en-us/library/ms714367.aspx) a estrutura que contém as propriedades e dos valores a serem definidos.  Consulte [Conjuntos de propriedades e grupos de propriedade](https://msdn.microsoft.com/en-us/library/ms713696.aspx)*na referência do programador do* OLE DB em [!INCLUDE[winSDK](../../atl/includes/winsdk_md.md)].  
  
 `pRowsAffected`  
 \[In\/out\] um ponteiro para a memória em que a contagem de linhas afetadas por um comando é retornada.  Se *\*pRowsAffected* é **nulo**, nenhuma contagem de linhas será retornado.  Caso contrário, **Abrir** define \*`pRowsAffected` de acordo com as seguintes condições:  
  
|Se|Then|  
|--------|----------|  
|O elemento de **cParamSets** de `pParams` é maior que 1|\*`pRowsAffected` representa o número total de linhas afetadas por todos os conjuntos de parâmetros especificados na execução.|  
|O número de linhas afetadas não está disponível|\*`pRowsAffected` é definido como 1.|  
|O comando não, não atualiza, exclui ou insere linhas não|\*`pRowsAffected` é indefinido.|  
  
 `guidCommand`  
 \[in\] GUID que especifica a sintaxe e as regras gerais para que o provedor usa em analisar o texto do comando.  Consulte [ICommandText::GetCommandText](https://msdn.microsoft.com/en-us/library/ms709825.aspx) e [ICommandText::SetCommandText](https://msdn.microsoft.com/en-us/library/ms709757.aspx)*na referência do programador de OLE DB* para obter detalhes.  
  
 `bBind`  
 \[in\] especifica se associar automaticamente o comando depois de ser executado.  A opção é **true**, o que faz com que o comando a ser associado automaticamente.  A configuração `bBind` a **false** impede a associação automático de comando para que você possa se associar manualmente. \(A associação é manual de interesse específico aos usuários OLAP\).  
  
 `ulPropSets`  
 \[in\] o número de estruturas de [DBPROPSET](https://msdn.microsoft.com/en-us/library/ms714367.aspx) transmitido no argumento *de pPropSet* .  
  
## Valor de retorno  
 `HRESULT`padrão.  
  
## Comentários  
 Os primeiros três formulários de **Abrir** usam uma sessão, crie um comando, e executa o comando, associando todos os parâmetros conforme necessário.  
  
 O primeiro formulário de **Abrir** usa uma cadeia de caracteres de comando Unicode e não tem nenhum valor padrão.  
  
 O segundo formulário de **Abrir** não usa uma cadeia de caracteres de comando ANSI e nenhum valor padrão \(fornecidos para compatibilidade com versões anteriores com os aplicativos existentes de ANSI\).  
  
 O terceiro formulário de **Abrir** permite que a cadeia de caracteres de comando é NULL, devido ao tipo `int` com um valor padrão de NULL.  Fornece chamando `Open(session, NULL);` ou `Open(session);` como NULL é do tipo `int`.  Esta versão exige e afirma que o parâmetro de `int` é NULL.  
  
 Use o quarto formulário de **Abrir** quando você já tiver criado um comando e você desejar executar único [Prepare](../../data/oledb/ccommand-prepare.md) e várias execuções.  
  
> [!NOTE]
>  **Abrir** chama **Executar**, que por sua vez `GetNextResult`.  
  
## Requisitos  
 **Header:** atldbcli.h  
  
## Consulte também  
 [Classe CCommand](../../data/oledb/ccommand-class.md)