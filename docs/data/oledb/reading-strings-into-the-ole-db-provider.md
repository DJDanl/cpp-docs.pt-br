---
title: Lendo cadeias de caracteres no provedor OLE DB | Microsoft Docs
ms.custom: ''
ms.date: 10/13/2018
ms.technology:
- cpp-data
ms.topic: reference
dev_langs:
- C++
helpviewer_keywords:
- OLE DB providers, reading strings into
ms.assetid: 517f322c-f37e-4eed-bf5e-dd9a412c2f98
author: mikeblome
ms.author: mblome
ms.workload:
- cplusplus
- data-storage
ms.openlocfilehash: 6521ed8078f4411b704678b53f16fbdbc4d04e73
ms.sourcegitcommit: c045c3a7e9f2c7e3e0de5b7f9513e41d8b6d19b2
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 10/24/2018
ms.locfileid: "49989873"
---
# <a name="reading-strings-into-the-ole-db-provider"></a>Lendo cadeias de caracteres no provedor de banco de dados OLE

O `RCustomRowset::Execute` função abre um arquivo e lê as cadeias de caracteres. O consumidor transmite o nome do arquivo para o provedor, chamando [ICommandText:: SetCommandText](/previous-versions/windows/desktop/ms709757). O provedor recebe o nome do arquivo e o armazena na variável de membro `m_szCommandText`. `Execute` lê o nome do arquivo de `m_szCommandText`. Se o nome do arquivo é inválido ou não estiver disponível, o arquivo `Execute` retornará um erro. Caso contrário, ele abre o arquivo e chama `fgets` para recuperar as cadeias de caracteres. Para cada conjunto de cadeias de caracteres-leituras, `Execute` cria uma instância de registro do usuário (`CAgentMan`) e o coloca em uma matriz.  
  
Se o arquivo não pode ser aberto, `Execute` deve retornar DB_E_NOTABLE. Se ele retornar E_FAIL em vez disso, o provedor não funcionará com muitos consumidores e não passa do OLE DB [testes de conformidade](../../data/oledb/testing-your-provider.md).  
  
## <a name="example"></a>Exemplo  

O editado `Execute` função tem esta aparência:  
  
```cpp
/////////////////////////////////////////////////////////////////////////  
// CustomRS.h  
class RCustomRowset : public CRowsetImpl< RCustomRowset, CAgentMan, CRCustomCommand>  
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