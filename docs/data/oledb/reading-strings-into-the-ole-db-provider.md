---
title: Lendo cadeias de caracteres no provedor OLE DB | Microsoft Docs
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology: cpp-windows
ms.tgt_pltfrm: 
ms.topic: article
dev_langs: C++
helpviewer_keywords: OLE DB providers, reading strings into
ms.assetid: 517f322c-f37e-4eed-bf5e-dd9a412c2f98
caps.latest.revision: "10"
author: mikeblome
ms.author: mblome
manager: ghogen
ms.workload:
- cplusplus
- data-storage
ms.openlocfilehash: e798b3e85bbb5d6b362900c25d4c3414458ea63d
ms.sourcegitcommit: 8fa8fdf0fbb4f57950f1e8f4f9b81b4d39ec7d7a
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 12/21/2017
---
# <a name="reading-strings-into-the-ole-db-provider"></a>Lendo cadeias de caracteres no provedor de banco de dados OLE
O `RMyProviderRowset::Execute` função abre um arquivo e lê cadeias de caracteres. O consumidor transmite o nome do arquivo para o provedor chamando [ICommandText:: SetCommandText](https://msdn.microsoft.com/en-us/library/ms709757.aspx). O provedor recebe o nome do arquivo e o armazena na variável de membro `m_szCommandText`. `Execute`lê o nome de arquivo `m_szCommandText`. Se o nome do arquivo é inválido ou não estiver disponível, o arquivo `Execute` retornará um erro. Caso contrário, ele abre o arquivo e chamadas `fgets` para recuperar as cadeias de caracteres. Para cada conjunto de cadeias de caracteres-leituras, `Execute` cria uma instância de registro do usuário (`CAgentMan`) e o coloca em uma matriz.  
  
 Se o arquivo não pode ser aberto, `Execute` deve retornar **DB_E_NOTABLE**. Se ele retorna **E_FAIL** em vez disso, o provedor não funcionará com vários consumidores e não passará o OLE DB [testes de conformidade](../../data/oledb/testing-your-provider.md).  
  
## <a name="example"></a>Exemplo  
  
### <a name="description"></a>Descrição  
 O editado `Execute` função tem esta aparência:  
  
### <a name="code"></a>Código  
  
```  
/////////////////////////////////////////////////////////////////////////  
// MyProviderRS.h  
class RMyProviderRowset : public CRowsetImpl< RMyProviderRowset, CAgentMan, CRMyProviderCommand>  
{  
public:  
    HRESULT Execute(DBPARAMS * pParams, LONG* pcRowsAffected)  
    {  
        enum {  
            sizeOfBuffer = 256,  
            sizeOfFile = MAX_PATH  
        };  
        USES_CONVERSION;  
        FILE* pFile = NULL;  
        TCHAR szString[sizeOfBuffer];  
        TCHAR szFile[sizeOfFile];  
        size_t nLength;        errcodeerr;  
  
        ObjectLock lock(this);  
  
        // From a filename, passed in as a command text, scan the file  
        // placing data in the data array.  
        if (!m_szCommandText)  
        {  
            ATLTRACE("No filename specified");  
            return E_FAIL;  
        }  
  
        // Open the file  
        _tcscpy_s(szFile, sizeOfFile, m_szCommandText);  
        if (szFile[0] == _T('\0') ||   
            ((err = fopen_s(&pFile, &szFile[0], "r")) == 0))  
        {  
            ATLTRACE("Could not open file");  
            return DB_E_NOTABLE;  
        }  
  
        // Scan and parse the file.  
        // The file should contain two strings per record  
        LONG cFiles = 0;  
        while (fgets(szString, sizeOfBuffer, pFile) != NULL)  
        {  
            nLength = strnlen(szString, sizeOfBuffer);  
            szString[nLength-1] = '\0';   // Strip off trailing CR/LF  
            CAgentMan am;  
            _tcscpy_s(am.szCommand, am.sizeOfCommand, szString);  
            _tcscpy_s(am.szCommand2, am.sizeOfCommand2, szString);  
  
            if (fgets(szString, sizeOfBuffer, pFile) != NULL)  
            {  
                nLength = strnlen(szString, sizeOfBuffer);  
                szString[nLength-1] = '\0'; // Strip off trailing CR/LF  
                _tcscpy_s(am.szText, am.sizeOfText, szString);  
                _tcscpy_s(am.szText2, am.sizeOfText2, szString);  
            }  
  
            am.dwBookmark = ++cFiles;  
            if (!m_rgRowData.Add(am))  
            {  
                ATLTRACE("Couldn't add data to array");  
                fclose(pFile);  
                return E_FAIL;  
            }  
        }  
  
        if (pcRowsAffected != NULL)  
            *pcRowsAffected = cFiles;  
        return S_OK;  
    }  
}  
```  
  
## <a name="see-also"></a>Consulte também  
 [Implementando o provedor somente leitura simples](../../data/oledb/implementing-the-simple-read-only-provider.md)