---
title: "Registro de usu&#225;rio | Microsoft Docs"
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
  - "Provedores OLE DB, registro de usuário"
  - "registros, usuário"
  - "conjuntos de linhas, registro de usuário"
  - "registros de usuário"
  - "registros de usuário, descrito"
ms.assetid: 9c0d2864-2738-4f62-a750-1016d9c3523f
caps.latest.revision: 8
caps.handback.revision: 8
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# Registro de usu&#225;rio
[!INCLUDE[vs2017banner](../../assembler/inline/includes/vs2017banner.md)]

O registro de usuário fornece código e a estrutura de dados que representa os dados de coluna para um conjunto de linhas.  Um registro de usuário pode ser criado em tempo de compilação ou em tempo de execução.  Quando você cria um provedor que usa o assistente do provedor OLE DB de ATL, o assistente cria um registro de usuário padrão que tenha esta aparência \(assumindo o especificou um nome de provedor \[\] nome curto de MyProvider “”\):  
  
```  
class CWindowsFile:  
   public WIN32_FIND_DATA  
{  
public:  
  
BEGIN_PROVIDER_COLUMN_MAP(CMyProviderWindowsFile)  
   PROVIDER_COLUMN_ENTRY("FileAttributes", 1, dwFileAttributes)  
   PROVIDER_COLUMN_ENTRY("FileSizeHigh", 2, nFileSizeHigh)  
   PROVIDER_COLUMN_ENTRY("FileSizeLow", 3, nFileSizeLow)  
   PROVIDER_COLUMN_ENTRY_STR("FileName", 4, cFileName)  
   PROVIDER_COLUMN_ENTRY_STR("AltFileName", 5, cAlternateFileName)  
END_PROVIDER_COLUMN_MAP()  
  
};  
```  
  
 Os modelos do provedor OLE DB trata todos os OLE DB específicos em relação às interações com o cliente.  Para adquirir os dados da coluna necessários para uma resposta, o provedor chamará a função de `GetColumnInfo` , que você deve colocar no registro do usuário.  Você pode substituir explicitamente `GetColumnInfo` no registro do usuário, por exemplo, declarando no arquivo de .h como mostrado a seguir:  
  
```  
template <class T>  
static ATLCOLUMNINFO* GetColumnInfo(T* pThis, ULONG* pcCols)   
```  
  
 Isso é equivalente a:  
  
```  
static ATLCOLUMNINFO* GetColumnInfo(CommandClass* pThis, ULONG* pcCols)  
static ATLCOLUMNINFO* GetColumnInfo(RowsetClass* pThis, ULONG* pcCols)  
```  
  
 Você também deve implementar `GetColumnInfo` no arquivo .cpp do registro do usuário.  
  
 O auxílio de macros de PROVIDER\_COLUMN\_MAP na criação de uma função de `GetColumnInfo` :  
  
-   BEGIN\_PROVIDER\_COLUMN\_MAP define o protótipo da função estática e uma matriz de estruturas de **ATLCOLUMNINFO** .  
  
-   PROVIDER\_COLUMN\_ENTRY define e inicializa único **ATLCOLUMNINFO**.  
  
-   END\_PROVIDER\_COLUMN\_MAP fecha a matriz e a função.  Também coloca a contagem de elementos da matriz para o parâmetro de `pcCols` .  
  
 Quando um registro de usuário for criado em tempo de execução, **GetColumnInfo** usa o parâmetro de `pThis` para receber um ponteiro para uma instância do conjunto de linhas ou do comando.  Os comandos e os conjuntos de linhas devem oferecer suporte à interface de `IColumnsInfo` , de modo que as informações de coluna pode ser obtida desse ponteiro.  
  
 **CommandClass** e **RowsetClass** são o comando e o conjunto de linhas que usam o registro do usuário.  
  
 Para obter um exemplo mais detalhado de como substituir `GetColumnInfo` em um registro de usuário, consulte [Dinamicamente determinando as colunas retornadas ao consumidor](../../data/oledb/dynamically-determining-columns-returned-to-the-consumer.md).  
  
## Consulte também  
 [Arquitetura de modelo do provedor de banco de dados OLE](../../data/oledb/ole-db-provider-template-architecture.md)