---
title: selectany | Microsoft Docs
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology: cpp-language
ms.tgt_pltfrm: 
ms.topic: language-reference
f1_keywords: selectany_cpp
dev_langs: C++
helpviewer_keywords:
- __declspec keyword [C++], selectany
- selectany __declspec keyword
ms.assetid: 9c353017-5a42-4f50-b741-bd13da1ce84d
caps.latest.revision: "7"
author: mikeblome
ms.author: mblome
manager: ghogen
ms.openlocfilehash: 37acdf0d1784ecfc9893c676f2c056902d56344c
ms.sourcegitcommit: ebec1d449f2bd98aa851667c2bfeb7e27ce657b2
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 10/24/2017
---
# <a name="selectany"></a>selectany
**Seção específica da Microsoft**  
  
 Informa ao compilador que o item de dados global declarado (variável ou objeto) é uma COMDAT aleatória (uma função compactada).  
  
## <a name="syntax"></a>Sintaxe  
  
```  
__declspec( selectany ) declarator  
```  
  
## <a name="remarks"></a>Comentários  
 No tempo de link, se várias definições de uma COMDAT forem consideradas, o vinculador escolherá uma e descartará o restante. Se a opção de vinculador [/OPT: REF](../build/reference/opt-optimizations.md) (otimizações) estiver marcada, a eliminação de COMDAT ocorrerá para remover todos os itens de dados não referenciados na saída do vinculador.  
  
 Os construtores e a atribuição pela função ou por métodos estáticos globais na declaração não criarão uma referência e não impedirão a eliminação de /OPT:REF. Os efeitos colaterais desse código não devem depender de quando não houver nenhuma outra referência aos dados.  
  
 Para objetos globais dinamicamente inicializados, `selectany` descartará também o código de inicialização de um objeto não referenciado.  
  
 Um item de dados global normalmente pode ser inicializado apenas uma vez em um projeto EXE ou DLL. `selectany` pode ser usado na inicialização dos dados globais definidos por cabeçalhos quando o mesmo cabeçalho aparecer em mais de um arquivo de origem. `selectany` está disponível nos compiladores C e C++.  
  
> [!NOTE]
>  `selectany` só pode ser aplicado à inicialização real dos itens de dados globais que podem ser vistos externamente.  
  
## <a name="example"></a>Exemplo  
 Este código mostra como usar o atributo `selectany`.  
  
```  
//Correct - x1 is initialized and externally visible   
__declspec(selectany) int x1=1;  
  
//Incorrect - const is by default static in C++, so   
//x2 is not visible externally (This is OK in C, since  
//const is not by default static in C)  
const __declspec(selectany) int x2 =2;  
  
//Correct - x3 is extern const, so externally visible  
extern const __declspec(selectany) int x3=3;  
  
//Correct - x4 is extern const, so it is externally visible  
extern const int x4;  
const __declspec(selectany) int x4=4;  
  
//Incorrect - __declspec(selectany) is applied to the uninitialized  
//declaration of x5  
extern __declspec(selectany) int x5;  
  
// OK: dynamic initialization of global object  
class X {  
public:  
X(int i){i++;};  
int i;  
};  
  
__declspec(selectany) X x(1);  
```  
  
## <a name="example"></a>Exemplo  
 Este código mostra como usar o `selectany` atributo para garantir que dados dobra COMDAT quando você usar também o [/OPT: ICF](../build/reference/opt-optimizations.md) opção de vinculador. Observe que os dados devem ser marcados com `selectany` e colocada em uma **const** seção (somente leitura). Você deve especificar explicitamente a seção somente leitura.  
  
```  
// selectany2.cpp  
// in the following lines, const marks the variables as read only  
__declspec(selectany) extern const int ix = 5;  
__declspec(selectany) extern const int jx = 5;  
int main() {  
   int ij;  
   ij = ix + jx;  
}  
```  
  
 **Fim da seção específica da Microsoft**  
  
## <a name="see-also"></a>Consulte também  
 [declspec](../cpp/declspec.md)   
 [Palavras-chave](../cpp/keywords-cpp.md)