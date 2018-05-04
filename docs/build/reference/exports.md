---
title: EXPORTAÇÕES | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-tools
ms.topic: reference
f1_keywords:
- EXPORTS
dev_langs:
- C++
helpviewer_keywords:
- EXPORTS .def file statement
ms.assetid: dbcd7579-b855-44c4-bd27-931e157657f7
author: corob-msft
ms.author: corob
ms.workload:
- cplusplus
ms.openlocfilehash: 7cc7a9995fdc5be786712752e30015337b9f1607
ms.sourcegitcommit: be2a7679c2bd80968204dee03d13ca961eaa31ff
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 05/03/2018
---
# <a name="exports"></a>EXPORTS
Introduz uma seção de uma ou mais definições de exportação que especificam os nomes exportados ou ordenais de funções ou dados. Cada definição deve ficar em uma linha separada.  
  
```  
EXPORTS  
   definition  
```  
  
## <a name="remarks"></a>Comentários  
 A primeira `definition` pode estar na mesma linha que a palavra-chave `EXPORTS` ou em uma linha subsequente. O arquivo .DEF pode conter uma ou mais instruções `EXPORTS`.  
  
 A sintaxe para uma `definition` de exportação é:  
  
```  
  
entryname[=internalname] [@ordinal [NONAME]] [[PRIVATE] | [DATA]]  
```  
  
 O `entryname` é o nome de função ou variável que você deseja exportar. É obrigatório. Se o nome exportado for diferente do nome no DLL, especifique o nome da exportação no DLL usando `internalname`. Por exemplo, se o DLL exportar uma função `func1` e você desejar que os chamadores a utilizem como `func2`, especifique:  
  
```  
EXPORTS  
   func2=func1  
```  
  
 Como o compilador Visual C++ usa decoração de nome para funções C++, é preciso usar o nome decorado como `entryname` ou `internalname` ou definir as funções exportadas usando `extern "C"` no código-fonte. O compilador decora também funções de C que usam o [stdcall](../../cpp/stdcall.md) chamada com um prefixo de sublinhado (_) e um sufixo composto o sinal de arroba (@) seguido pelo número de bytes (em decimal) na lista de argumentos.  
  
 Para localizar os nomes decorados produzidos pelo compilador, use o [DUMPBIN](../../build/reference/dumpbin-reference.md) ferramenta ou o vinculador [/MAPEAR](../../build/reference/map-generate-mapfile.md) opção. Os nomes decorados são específicos do compilador. Se você exportar os nomes decorados no arquivo .DEF, executáveis vinculados ao DLL também devem ser construídos com a mesma versão do compilador. Isso garante que os nomes decorados no chamador correspondam aos nomes exportados no arquivo .DEF.  
  
 É possível usar @`ordinal` para especificar que um número, e não o nome da função, irá na tabela de exportação do DLL. Muitos DLLs do Windows exportam ordinais para dar suporte a código legado. Era comum usar ordinais em código do Windows de 16 bits, pois isso podia ajudar a minimizar o tamanho de um DLL. Não recomendamos exportar funções por ordinais, a menos que os clientes DLL precisem disso para suporte legado. Como o arquivo .LIB conterá o mapeamento entre o ordinal e a função, é possível usar o nome da função como normalmente se faria em projetos que usam o DLL.  
  
 Usando a palavra-chave `NONAME` opcional, é possível exportar apenas por ordinal e reduzir o tamanho da tabela de exportação no DLL resultante. No entanto, se você quiser usar [GetProcAddress](http://msdn.microsoft.com/library/windows/desktop/ms683212.aspx) na DLL, você deve saber o número ordinal porque o nome não será válido.  
  
 A palavra-chave `PRIVATE` opcional impede que o `entryname` seja incluído na biblioteca de importação gerada por LINK. Não afeta a exportação na imagem também gerada por LINK.  
  
 A palavra-chave `DATA` opcional especifica que uma exportação é de dados, não código. Esse exemplo mostra como exportar uma variável de dados chamada `exported_global`:  
  
```  
EXPORTS  
   exported_global DATA  
```  
  
 Há quatro maneiras de exportar uma definição, listadas na ordem recomendada:  
  
1.  O [dllexport](../../cpp/dllexport-dllimport.md) palavra-chave no código-fonte  
  
2.  Uma instrução `EXPORTS` em um arquivo .DEF  
  
3.  Um [/exportação](../../build/reference/export-exports-a-function.md) especificação em um comando LINK  
  
4.  Um [comentário](../../preprocessor/comment-c-cpp.md) diretiva no código-fonte do formulário `#pragma comment(linker, "/export: definition ")`  
  
 Todos os quatro métodos podem ser usados no mesmo programa. Quando LINK compila um programa que contém exportações, ele também cria uma biblioteca de importação, a menos que um arquivo .EXP seja usado na construção.  
  
 Segue um exemplo de seção EXPORTS:  
  
```  
EXPORTS  
   DllCanUnloadNow      @1          PRIVATE  
   DllWindowName = WindowName       DATA  
   DllGetClassObject    @4 NONAME   PRIVATE  
   DllRegisterServer    @7  
   DllUnregisterServer  
```  
  
 Ao exportar uma variável de um DLL usando um arquivo .DEF, não é necessário especificar `__declspec(dllexport)` na variável. Porém, em qualquer arquivo que use o DLL, ainda é preciso usar `__declspec(dllimport)` na declaração de dados.  
  
## <a name="see-also"></a>Consulte também  
 [Regras para instruções de definição do módulo](../../build/reference/rules-for-module-definition-statements.md)