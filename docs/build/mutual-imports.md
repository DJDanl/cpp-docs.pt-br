---
title: "Importações mútuas | Microsoft Docs"
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology: cpp-tools
ms.tgt_pltfrm: 
ms.topic: article
dev_langs: C++
helpviewer_keywords:
- mutual DLL imports [C++]
- AFX_DATA
- importing DLLs [C++], mutual imports
- mutually importing executable files [C++]
- AFX_EXT_CLASS macro
- circular imports
- _AFXEXT preprocessor symbol
- DLLs [C++], importing
- executable files [C++], importing
- extension DLLs [C++], mutual imports
- exporting DLLs [C++], mutual imports
ms.assetid: 2cc29537-92ee-4d92-af39-8b8b3afd808f
caps.latest.revision: "7"
author: corob-msft
ms.author: corob
manager: ghogen
ms.workload: cplusplus
ms.openlocfilehash: bfd31cd4e5776555137daf002c076e14d4031f89
ms.sourcegitcommit: 8fa8fdf0fbb4f57950f1e8f4f9b81b4d39ec7d7a
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 12/21/2017
---
# <a name="mutual-imports"></a>Importações mútuas
Exportar ou importar para outro arquivo executável apresenta complicações quando as Importações mútuas (ou circular). Por exemplo, duas DLLs importar símbolos umas das outras, como funções mutuamente recursivas.  
  
 Importando arquivos executáveis (normalmente DLLs) mutuamente o problema é que não pode ser criado sem criar outros primeiro. Cada processo de compilação requer, como entrada, uma biblioteca de importação produzida pelo processo de compilação.  
  
 A solução é usar o utilitário LIB com a opção /DEF, que produz uma biblioteca de importação sem criar o arquivo executável. Usando esse utilitário, você pode criar todas as bibliotecas de importação é necessário, não importa quantas DLLs envolvidos ou complicado como as dependências são.  
  
 A solução geral para lidar com Importações mútuas é:  
  
1.  Levar cada DLL sucessivamente. (Qualquer ordem é viável, embora alguns pedidos são melhores.) Se todas as bibliotecas de importação necessário existem e sejam atuais, execute o LINK para criar o arquivo executável (DLL). Isso produz uma biblioteca de importação. Caso contrário, execute LIB para produzir uma biblioteca de importação.  
  
     Executando lb com a opção /DEF produz um arquivo adicional com um. Extensão EXP. A. Arquivos EXP devem ser usado posteriormente para criar o arquivo executável.  
  
2.  Depois de usar o LINK ou LIB para criar todas as bibliotecas de importação, volte e executar o LINK para compilar todos os arquivos executáveis que não foram criados na etapa anterior. Observe que o arquivo. EXP correspondente deve ser especificado na linha de LINK.  
  
     Se você tinha executar o utilitário LIB anteriormente para produzir uma biblioteca de importação para DLL1, LIB deve ter produzido o arquivo DLL1.exp também. Você deve usar DLL1.exp como entrada para o LINK ao criar DLL1.dlll.  
  
 A ilustração a seguir mostra uma solução para duas DLLs mutuamente importação, DLL1 e DLL2. Etapa 1 é executar LIB, com a opção /DEF definida, em DLL1. Etapa 1 produz DLL1.lib, uma biblioteca de importação e DLL1.exp. Na etapa 2, a biblioteca de importação é usada para criar DLL2, que por sua vez produz uma biblioteca de importação para símbolos do DLL2. Etapa 3 cria DLL1, usando DLL1.exp e DLL2.lib como entrada. Observe que um arquivo. EXP para DLL2 não é necessário porque LIB não foi usado para criar a biblioteca de importação do DLL2.  
  
 ![Usando Importações mútuas vincular duas DLLs](../build/media/vc37yj1.gif "vc37YJ1")  
Vinculando duas DLLs com Importações mútuas  
  
## <a name="limitations-of-afxext"></a>Limitações de afxext  
 Você pode usar o `_AFXEXT` símbolo do pré-processador para a sua extensão MFC DLLs, desde que você não tem várias camadas de DLLs de extensão do MFC. Se você tiver a extensão de MFC que chame ou derivar de classes em sua própria extensão de MFC, que, em seguida, derivam as classes MFC, você deve usar seu próprio símbolo do pré-processador para evitar ambiguidade.  
  
 O problema é que Win32 no, você deve declarar explicitamente todos os dados como **dllexport** se é para ser exportada de uma DLL, e **__declspec(dllimport)** se ele será importado de uma DLL. Quando você define `_AFXEXT`, os cabeçalhos MFC Verifique se **AFX_EXT_CLASS** está definido corretamente.  
  
 Quando você tiver várias camadas, um símbolo, como **AFX_EXT_CLASS** não é suficiente, porque uma DLL de extensão do MFC pode ser exportando novas classes, bem como importação outras classes do outro DLL de extensão do MFC. Para resolver esse problema, use um símbolo do pré-processador especial que indica que você está criando a DLL em comparação a utilizar a DLL. Por exemplo, imagine duas DLLs de extensão do MFC,. dll e b. dll. Cada um deles exportar algumas classes em A.h e B.h, respectivamente. B. dll usa as classes do. dll. Os arquivos de cabeçalho deve ter esta aparência:  
  
```  
/* A.H */  
#ifdef A_IMPL  
   #define CLASS_DECL_A   __declspec(dllexport)  
#else  
   #define CLASS_DECL_A   __declspec(dllimport)  
#endif  
  
class CLASS_DECL_A CExampleA : public CObject  
{ ... class definition ... };  
  
// B.H  
#ifdef B_IMPL  
   #define CLASS_DECL_B   __declspec(dllexport)  
#else  
   #define CLASS_DECL_B   __declspec(dllimport)  
#endif  
  
class CLASS_DECL_B CExampleB : public CExampleA  
{ ... class definition ... };  
...  
```  
  
 Quando é compilado. dll, que é compilado com `/D A_IMPL` e quando o b. dll é criado, ele é compilado com `/D B_IMPL`. Usando símbolos separados para cada DLL `CExampleB` é exportado e `CExampleA` é importado durante a criação de b. dll. `CExampleA`é exportada ao compilar. dll e importada quando usado por b. dll (ou outro cliente).  
  
 Esse tipo de camada não pode ser feito ao usar o interno **AFX_EXT_CLASS** e `_AFXEXT` símbolos de pré-processamento. A técnica descrita acima resolve esse problema de maneira diferente não que o mecanismo MFC em si usa ao criar seu ativas tecnologias, banco de dados e DLLs de extensão do MFC de rede.  
  
## <a name="not-exporting-the-entire-class"></a>Não exportar a classe inteira  
 Quando você não estiver exportando toda uma classe, você precisa garantir que os itens de dados necessários criados pelas macros MFC são exportados corretamente. Isso pode ser feito redefinindo `AFX_DATA` macro da sua classe específica. Isso deve ser feito a qualquer momento, que não exportar a classe inteira.  
  
 Por exemplo:  
  
```  
/* A.H */  
#ifdef A_IMPL  
   #define CLASS_DECL_A  _declspec(dllexport)  
#else  
   #define CLASS_DECL_A  _declspec(dllimport)  
#endif  
  
#undef  AFX_DATA  
#define AFX_DATA CLASS_DECL_A  
  
class CExampleA : public CObject  
{  
   DECLARE_DYNAMIC()  
   CLASS_DECL_A int SomeFunction();  
   //... class definition ...  
};  
  
#undef AFX_DATA  
#define AFX_DATA  
```  
  
### <a name="what-do-you-want-to-do"></a>O que você deseja fazer?  
  
-   [Exportação de uma DLL](../build/exporting-from-a-dll.md)  
  
-   [Exportação de uma DLL usando. Arquivos DEF](../build/exporting-from-a-dll-using-def-files.md)  
  
-   [Exportar de uma DLL usando dllexport](../build/exporting-from-a-dll-using-declspec-dllexport.md)  
  
-   [Exportar e importar usando AFX_EXT_CLASS](../build/exporting-and-importing-using-afx-ext-class.md)  
  
-   [Exportar funções C++ para uso em executáveis da linguagem C](../build/exporting-cpp-functions-for-use-in-c-language-executables.md)  
  
-   [Determinar qual método de exportação a ser usado](../build/determining-which-exporting-method-to-use.md)  
  
-   [Importar para um aplicativo usando __declspec(dllimport)](../build/importing-into-an-application-using-declspec-dllimport.md)  
  
### <a name="what-do-you-want-to-know-more-about"></a>Que mais você deseja saber?  
  
-   [O utilitário LIB e a opção /DEF](../build/reference/lib-reference.md)  
  
## <a name="see-also"></a>Consulte também  
 [Importando e exportando](../build/importing-and-exporting.md)